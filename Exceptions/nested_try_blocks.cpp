#include <iostream>
#include <stdexcept>

int main() {
    int option = 2;

    try {
        std::cout << "Outer try started\n";

        try {
            std::cout << "Inner try started\n";

            if (option == 1) {
                throw std::invalid_argument("Invalid input");
            }

            if (option == 2) {
                throw std::runtime_error("Operation failed");
            }
        }
        catch (const std::invalid_argument& error) {
            // Handles invalid input at the inner level.
            std::cout << "Inner catch: "
                      << error.what() << '\n';
        }

        std::cout << "After inner try/catch\n";
    }
    catch (const std::exception& error) {
        // Handles exceptions not caught by the inner handler.
        std::cout << "Outer catch: "
                  << error.what() << '\n';
    }

    std::cout << "Program continues\n";

    return 0;
}