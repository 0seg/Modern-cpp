
#include <barrier>
#include <iostream>
#include <syncstream>
#include <thread>
#include <vector>

int main() {
    constexpr int NUM_THREADS = 3;

    std::barrier sync_point(NUM_THREADS);
    std::vector<std::jthread> threads;

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back([i, &sync_point] {
            std::osyncstream(std::cout)
                << "Thread " << i << ": Phase 1\n";

            // Wait until all threads finish Phase 1.
            sync_point.arrive_and_wait();

            std::osyncstream(std::cout)
                << "Thread " << i << ": Phase 2\n";
        });
    }

    // jthread joins automatically when destroyed.
}
