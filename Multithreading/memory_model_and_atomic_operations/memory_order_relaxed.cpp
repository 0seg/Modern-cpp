
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

constexpr int NUM_THREADS = 8;
constexpr int ITERATIONS = 100'000;

std::atomic<int> counter{0};

void increment_counter() {
    for (int i = 0; i < ITERATIONS; ++i) {
        counter.fetch_add(1, std::memory_order_relaxed);
    }
}

int main() {
    std::vector<std::jthread> threads;
    threads.reserve(NUM_THREADS);

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(increment_counter);
    }

    // Wait for all threads to finish.
    threads.clear();

    const int expected = NUM_THREADS * ITERATIONS;
    const int actual = counter.load(std::memory_order_relaxed);

    std::cout << "Expected count: " << expected << '\n';
    std::cout << "Actual count:   " << actual << '\n';

    if (actual == expected) {
        std::cout << "All increments were recorded correctly!\n";
    } else {
        std::cout << "Counter mismatch!\n";
    }

    return 0;
}
