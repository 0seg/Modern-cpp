
#include <chrono>
#include <iostream>
#include <semaphore>
#include <syncstream>
#include <thread>
#include <vector>

int main() {
    constexpr int NUM_WORKERS = 5;
    constexpr int MAX_PERMITS = 2;

    std::counting_semaphore<MAX_PERMITS> semaphore(MAX_PERMITS);
    std::vector<std::jthread> workers;

    for (int i = 0; i < NUM_WORKERS; ++i) {
        workers.emplace_back([i, &semaphore] {
            semaphore.acquire();

            std::osyncstream(std::cout)
                << "Worker " << i << " entered.\n";

            std::this_thread::sleep_for(
                std::chrono::seconds(1)
            );

            std::osyncstream(std::cout)
                << "Worker " << i << " leaving.\n";

            semaphore.release();
        });
    }
}
