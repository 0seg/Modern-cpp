#include <iostream>
#include <thread>
#include <chrono>
#include <stack>
#include <memory>
#include <stdexcept>

template<typename T>
class SafeStack {
    std::stack<std::shared_ptr<T>> s;
    std::mutex mtx;

public:
    void push(T value) {
        std::lock_guard<std::mutex> lock(mtx);
        s.push(std::make_shared<T>(value));
    }

    std::shared_ptr<T> pop() {
        std::lock_guard<std::mutex> lock(mtx);
        if (!s.empty()) {
            std::shared_ptr<T> res(s.top());
            s.pop();
            return res;
        }
        throw std::runtime_error("Stack is empty");
    }

    bool empty() {
        std::lock_guard<std::mutex> lock(mtx);
        return s.empty();
    }

    size_t size() {
        std::lock_guard<std::mutex> lock(mtx);
        return s.size();
    }
};

int main() {
    SafeStack<int> safe_stack;

    // Thread 1: The Producer (pushes numbers from 1 to 5)
    std::thread producer([&]() {
        for (int i = 1; i <= 5; ++i) {
            safe_stack.push(i);
            std::cout << "[Producer] Pushed number: " << i << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    });

    // Thread 2: The Consumer (pops numbers from the stack)
    std::thread consumer([&]() {
        for (int i = 1; i <= 5; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(80)); // Small delay
            try {
                auto val = safe_stack.pop();
                std::cout << "[Consumer] -------> Popped number: " << *val << "\n";
            } catch (const std::exception& e) {
                std::cout << e.what() << "\n";
            }
        }
    });

    // Wait for both threads to finish execution
    producer.join();
    consumer.join();

    std::cout << "\nFinal stack empty? " << (safe_stack.empty() ? "Yes" : "No") << "\n";
}