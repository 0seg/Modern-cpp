#include <atomic>
#include <future>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <exception>

template<typename Iterator, typename MatchType>
Iterator parallel_find_async(
    Iterator begin,
    Iterator end,
    std::atomic<bool>* done,
    const MatchType& match)
{
    try
    {
        // Calculate the range size.
        unsigned long const length = std::distance(begin, end);
        unsigned long const min_per_thread = 25;

        if (length < 2 * min_per_thread)
        {
            // Search directly when the range is small.
            for (; begin != end && !done->load(); ++begin)
            {
                if (*begin == match)
                {
                    done->store(true);
                    return begin;
                }
            }

            return end;
        }
        else
        {
            // Split the range into two halves.
            Iterator const mid_point = begin + length / 2;

            // Search the right half asynchronously.
            std::future<Iterator> async_result = std::async(
                &parallel_find_async<Iterator, MatchType>,
                mid_point, end, done, match);

            // Search the left half in the current execution.
            Iterator const direct_result =
                parallel_find_async(begin, mid_point, done, match);

            // If the left half fails, retrieve the right-half result.
            return (direct_result == mid_point)
                ? async_result.get()
                : direct_result;
        }
    }
    catch (const std::exception&)
    {
        // Signal other executions and rethrow the exception.
        done->store(true);
        throw;
    }
}

int main()
{
    std::vector<int> numbers;

    // Create 100 elements, from 0 to 99.
    for (int i = 0; i < 100; ++i)
    {
        numbers.push_back(i);
    }

    int target = 73;
    std::atomic<bool> done(false);

    auto result = parallel_find_async(
        numbers.begin(),
        numbers.end(),
        &done,
        target
    );

    if (result != numbers.end())
    {
        std::cout << "Found: " << *result << '\n';
        std::cout << "Position: "
                  << std::distance(numbers.begin(), result)
                  << '\n';
    }
    else
    {
        std::cout << "Element not found.\n";
    }

    return 0;
}