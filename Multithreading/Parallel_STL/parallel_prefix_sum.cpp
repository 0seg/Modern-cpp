
#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <iterator>

// Calculates prefix sums inside one block.
template<typename Iterator>
auto partial_sum(Iterator begin, Iterator end)
{
    using Value = typename std::iterator_traits<Iterator>::value_type;

    Iterator previous = begin;
    Iterator current = begin;
    ++current;

    for (; current != end; ++current)
    {
        *current += *previous;
        previous = current;
    }

    return *previous;
}

template<typename Iterator>
void parallel_partial_sum(Iterator begin, Iterator end)
{
    auto length = std::distance(begin, end);

    if (length <= 0)
        return;

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

    if (num_threads == 1)
    {
        partial_sum(begin, end);
        return;
    }

    const auto block_size = length / num_threads;

    using Value = typename std::iterator_traits<Iterator>::value_type;

    std::vector<Iterator> block_begin(num_threads);
    std::vector<Iterator> block_end(num_threads);
    std::vector<Value> block_sums(num_threads);
    std::vector<Value> offsets(num_threads);

    Iterator current = begin;

    for (unsigned long i = 0; i < num_threads; ++i)
    {
        block_begin[i] = current;

        if (i == num_threads - 1)
            current = end;
        else
            std::advance(current, block_size);

        block_end[i] = current;
    }

    auto join_threads = [](std::vector<std::thread>& workers)
    {
        for (auto& worker : workers)
        {
            if (worker.joinable())
                worker.join();
        }
    };

    // Phase 1: Calculate local prefix sums in parallel.
    std::vector<std::thread> workers;
    workers.reserve(num_threads - 1);

    try
    {
        for (unsigned long i = 0; i < num_threads - 1; ++i)
        {
            workers.emplace_back([&, i]()
            {
                block_sums[i] =
                    partial_sum(block_begin[i], block_end[i]);
            });
        }
    }
    catch (...)
    {
        join_threads(workers);
        throw;
    }

    block_sums[num_threads - 1] =
        partial_sum(block_begin[num_threads - 1], end);

    join_threads(workers);

    // Phase 2: Calculate the offset for each block.
    Value total{};

    for (unsigned long i = 0; i < num_threads; ++i)
    {
        offsets[i] = total;
        total += block_sums[i];
    }

    // Phase 3: Apply offsets in parallel.
    workers.clear();

    try
    {
        for (unsigned long i = 0; i < num_threads - 1; ++i)
        {
            workers.emplace_back([&, i]()
            {
                for (Iterator it = block_begin[i];
                     it != block_end[i]; ++it)
                {
                    *it += offsets[i];
                }
            });
        }
    }
    catch (...)
    {
        join_threads(workers);
        throw;
    }

    for (Iterator it = block_begin[num_threads - 1];
         it != end; ++it)
    {
        *it += offsets[num_threads - 1];
    }

    join_threads(workers);
}

int main()
{
    std::vector<int> numbers(10000, 1);

    parallel_partial_sum(numbers.begin(), numbers.end());

    std::cout << "First: " << numbers.front() << '\n';
    std::cout << "Middle: " << numbers[4999] << '\n';
    std::cout << "Last: " << numbers.back() << '\n';

    return 0;
}
