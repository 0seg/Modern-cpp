```cpp
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> tasks;

void producer() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        tasks.push(42);
        std::cout << "Producer: task added\n";
    } // Releases the mutex.

    cv.notify_one(); // Wakes one waiting thread.
}

void consumer() {
    std::unique_lock<std::mutex> lock(mtx);

    std::cout << "Consumer: waiting for a task...\n";

    // Waits until the queue is not empty.
    cv.wait(lock, [] {
        return !tasks.empty();
    });

    int task = tasks.front();
    tasks.pop();

    std::cout << "Consumer: processing task " << task << '\n';
} // Releases the mutex.

int main() {
    std::thread consumer_thread(consumer);
    std::thread producer_thread(producer);

    producer_thread.join();
    consumer_thread.join();

    std::cout << "Main: all threads finished\n";
    return 0;
}
