#include <iostream>
#include <stdexcept>

// Level 1: Detects the error and throws an exception.
int divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }

    return a / b;
}

// Level 2: Calls divide() without handling its exception.
int calculate(int a, int b) {
    return divide(a, b);
}

int main() {
    try {
        // Level 3: Handles exceptions from the functions it calls.
        int result = calculate(10, 0);
        std::cout << "Result: " << result << '\n';
    }
    catch (const std::invalid_argument& error) {
        std::cout << "Error caught in main: "
                  << error.what() << '\n';
    }

    std::cout << "Program continues.\n";

    return 0;
}