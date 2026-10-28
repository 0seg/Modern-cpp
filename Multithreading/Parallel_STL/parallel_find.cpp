#include <vector>
#include <iostream>
#include <thread>
#include <future>
#include <atomic>
#include <algorithm>
#include <iterator>
#include <exception>
#include <mutex>

template<typename Iterator, typename MatchType>
Iterator parallel_find(Iterator begin, Iterator end, const MatchType& match)
{
    struct find_element {
        void operator()(
            Iterator begin,
            Iterator end,
            const MatchType& match,
            std::promise<Iterator>* result,
            std::atomic<bool>* done,
            std::mutex* result_mutex)
        {
            try {
                for (; begin != end && !done->load(); ++begin) {
                    if (*begin == match) {
                        std::lock_guard<std::mutex> lock(*result_mutex);

                        if (!done->load()) {
                            result->set_value(begin);
                            done->store(true);
                        }

                        return;
                    }
                }
            }
            catch (...) {

                std::lock_guard<std::mutex> lock(*result_mutex);

                if (!done->load()) {
                    result->set_exception(std::current_exception());
                    done->store(true);
                }
            }
        }
    };

    const auto length = std::distance(begin, end);

    if (length <= 0)
        return end;

    const unsigned long min_per_thread = 25;

    const unsigned long max_threads =
        (static_cast<unsigned long>(length) + min_per_thread - 1)
        / min_per_thread;

    const unsigned long hardware_threads =
        std::thread::hardware_concurrency();

    const unsigned long num_threads = std::min(
        hardware_threads != 0 ? hardware_threads : 2UL,
        max_threads
    );

    const auto block_size = length / num_threads;

    std::promise<Iterator> result;
    std::future<Iterator> future_result = result.get_future();

    std::atomic<bool> done(false);
    std::mutex result_mutex;

    std::vector<std::thread> threads(num_threads - 1);

    try {
        Iterator block_start = begin;

        for (unsigned long i = 0; i < num_threads - 1; ++i) {
            Iterator block_end = block_start;
            std::advance(block_end, block_size);

            threads[i] = std::thread(
                find_element{},
                block_start,
                block_end,
                match,
                &result,
                &done,
                &result_mutex
            );

            block_start = block_end;
        }

        find_element{}(
            block_start,
            end,
            match,
            &result,
            &done,
            &result_mutex
        );
    }
    catch (...) {
        done.store(true);
        for (auto& thread : threads) {
            if (thread.joinable())
                thread.join();
        }

        throw;
    }

    for (auto& thread : threads) {
        if (thread.joinable())
            thread.join();
    }

    if (!done.load())
        return end;

    return future_result.get();
}

int main()
{
    std::vector<int> numbers = {
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100
    };

    int target = 60;

    auto result = parallel_find(
        numbers.begin(),
        numbers.end(),
        target
    );

    if (result != numbers.end()) {
        std::cout << "Found: " << *result << '\n';

        std::cout << "Position: "
                  << std::distance(numbers.begin(), result)
                  << '\n';
    }
    else {
        std::cout << "Element not found.\n";
    }

    return 0;
}