#include <iostream>
#include <thread>
#include <chrono>

// Function that takes an argument
void threadFunction(int id) {
    std::cout << "Thread #" << id << " is running.\n";
}

int main(){

    // Launching a thread and passing an argument (e.g., 42)
    std::thread t1(threadFunction, 42);

    // Get the ID of the thread
    std::cout << "Thread ID: " << t1.get_id() << "\n";

    // Sleep for 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Yield the thread (hint to scheduler to let other threads run)
    std::this_thread::yield();

    // Hardware concurrency (number of concurrent threads supported, usually CPU cores)
    std::cout << "Hardware concurrency: " << std::thread::hardware_concurrency() << "\n";

    // Check if the thread is joinable before joining
    if (t1.joinable()) {
        t1.join(); // Crucial: wait for t1 to finish before main exits
        std::cout << "Thread joined successfully.\n";
    }

    return 0;
}
