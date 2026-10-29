
#include <chrono>
#include <iostream>
#include <semaphore>
#include <syncstream>
#include <thread>
#include <vector>

int main() {
    std::binary_semaphore semaphore(1);
    std::vector<std::jthread> workers;

    for (int i = 0; i < 3; ++i) {
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
