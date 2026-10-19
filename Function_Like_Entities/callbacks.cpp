#include <iostream>

// A regular function that will be used as a callback.
void printResult(int result) {
    std::cout << "Result: " << result << '\n';
}

// Accepts any callable object compatible with callback(result).
template <typename Callback>
void processNumber(int value, Callback callback) {
    int result = value * 2;

    // Execute the callback with the processed result.
    callback(result);
}

int main() {
    // Callback using a regular function.
    processNumber(10, printResult);

    // Callback using a lambda.
    processNumber(7, [](int result) {
        std::cout << "Squared result: "
                  << result * result << '\n';
    });

    // Callback using a lambda that captures a variable.
    int factor = 3;

    processNumber(5, [factor](int result) {
        std::cout << "Result multiplied by factor: "
                  << result * factor << '\n';
    });

    return 0;
}