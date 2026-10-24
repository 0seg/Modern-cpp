#include <iostream>
#include <thread>
#include <atomic>

int main() {
    // std::atomic ensures thread-safe, lock-free variable sharing
    std::atomic<int> counter{0};

    // Two threads incrementing the same variable concurrently 
    // without data races or corrupted values
    std::thread t1([&]() { for(int i = 0; i < 1000; ++i) counter++; });
    std::thread t2([&]() { for(int i = 0; i < 1000; ++i) counter++; });

    t1.join();
    t2.join();

    // Final result is always safely guaranteed to be 2000
    std::cout << "Total: " << counter << "\n";
}