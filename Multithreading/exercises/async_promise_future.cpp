
#include <chrono>
#include <future>
#include <iostream>
#include <thread>
#include <stdexcept>

// Simulates a task that takes time.
int calculate(int value) {

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    return value * value;
}

// Demonstrates std::async and std::future.
void async_example() {
    std::cout << "\n--- async ---\n";

    auto result = std::async(std::launch::async, calculate, 5);

    std::cout << "Task started\n";
    std::cout << "Result: " << result.get() << '\n';
}

// Demonstrates deferred execution.
void deferred_example() {
    std::cout << "\n--- deferred ---\n";

    auto result = std::async(std::launch::deferred, calculate, 6);

    std::cout << "Task created, not executed yet\n";
    std::cout << "Result: " << result.get() << '\n';
}

// Demonstrates std::promise and std::future.
void promise_example() {
    std::cout << "\n--- promise ---\n";

    std::promise<int> promise;
    std::future<int> result = promise.get_future();

    std::thread worker([](std::promise<int> p) {
            try {
                p.set_value(calculate(7));
            } catch (...) {
                p.set_exception(std::current_exception());
            }
        },
        std::move(promise)
    );

    std::cout << "Waiting for the result...\n";
    std::cout << "Result: " << result.get() << '\n';

    worker.join();
}

// Demonstrates exception propagation through a future.
void exception_example() {
    std::cout << "\n--- exception ---\n";

    std::promise<int> promise;
    auto result = promise.get_future();

    promise.set_exception(std::make_exception_ptr(std::runtime_error("Calculation failed")));

    try {
        result.get();
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
}

int main() {
    async_example();
    deferred_example();
    promise_example();
    exception_example();

    return 0;
}
