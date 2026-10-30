
#include <atomic>
#include <iostream>
#include <thread>

int shared_data = 0;
std::atomic<bool> data_ready{false};

void producer() {
    // Prepare the data.
    shared_data = 100;

    // Publish the data to other threads.
    data_ready.store(true, std::memory_order_release);

    std::cout << "Producer: data published\n";
}

void consumer() {
    // Wait until the data is published.
    while (!data_ready.load(std::memory_order_acquire)) {
        data_ready.wait(false, std::memory_order_relaxed);
    }

    // Safely access the published data.
    std::cout << "Consumer: received data = "
              << shared_data << '\n';
}

int main() {
    std::jthread producer_thread(producer);
    std::jthread consumer_thread(consumer);

    return 0;
}
