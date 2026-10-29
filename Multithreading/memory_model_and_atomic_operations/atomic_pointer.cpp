
#include <atomic>
#include <iostream>

int main() {
    int first = 100;
    int second = 200;
    int third = 300;

    std::atomic<int*> ptr{&first};

    // Load the current pointer.
    std::cout << "Initial value: "
              << *ptr.load() << '\n';

    // Store a new pointer.
    ptr.store(&second);

    std::cout << "After store:    "
              << *ptr.load() << '\n';

    // Exchange the pointer and retrieve the previous one.
    int* previous = ptr.exchange(&third);

    std::cout << "Previous value: "
              << *previous << '\n';

    std::cout << "After exchange: "
              << *ptr.load() << '\n';

    // Compare and exchange.
    int* expected = &third;

    bool success = ptr.compare_exchange_strong(
        expected,
        &first
    );

    std::cout << std::boolalpha;
    std::cout << "CAS successful: "
              << success << '\n';

    std::cout << "Final value:    "
              << *ptr.load() << '\n';

    return 0;
}
