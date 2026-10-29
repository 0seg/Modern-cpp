
#include <atomic>
#include <iostream>

int main() {
    std::atomic<int> value{10};

    std::cout << "Initial value: " << value.load() << "\n\n";

    // Example 1: Successful compare_exchange_strong.
    int expected = 10;

    bool success = value.compare_exchange_strong(expected, 20);

    std::cout << "Example 1: Successful comparison\n";
    std::cout << "Operation successful: " << std::boolalpha << success << '\n';
    std::cout << "Current value: " << value.load() << '\n';
    std::cout << "Expected value: " << expected << "\n\n";

    // Example 2: Failed compare_exchange_strong.
    expected = 10;

    success = value.compare_exchange_strong(expected, 30);

    std::cout << "Example 2: Failed comparison\n";
    std::cout << "Operation successful: " << success << '\n';
    std::cout << "Current value: " << value.load() << '\n';
    std::cout << "Updated expected: " << expected << "\n\n";

    // Example 3: Successful compare_exchange_weak with retry.
    expected = value.load();

    while (!value.compare_exchange_weak(expected, 40)) {
        // Retry if the comparison fails.
    }

    std::cout << "Example 3: compare_exchange_weak\n";
    std::cout << "Current value: " << value.load() << '\n';
    std::cout << "Expected value: " << expected << '\n';

    return 0;
}
