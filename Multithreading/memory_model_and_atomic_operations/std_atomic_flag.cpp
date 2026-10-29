
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::atomic_flag lock{};
int counter = 0;

void increment_counter() {
    for (int i = 0; i < 100'000; ++i) {
        while (lock.test_and_set()) {
            lock.wait(true);
        }

        ++counter;

        lock.clear();
        lock.notify_one();
    }
}

int main() {
    constexpr int NUM_THREADS = 4;
    constexpr int ITERATIONS = 100'000;

    std::vector<std::jthread> threads;
    threads.reserve(NUM_THREADS);

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(increment_counter);
    }

    // Wait for all threads to finish.
    threads.clear();

    std::cout << "Expected counter: "
              << NUM_THREADS * ITERATIONS << '\n';

    std::cout << "Actual counter:   "
              << counter << '\n';

    return 0;
}
