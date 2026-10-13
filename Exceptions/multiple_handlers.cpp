#include <iostream>
#include <stdexcept>

void process(int option) {
    // Each option throws a different type of exception.
    switch (option) {
        case 1:
            throw std::invalid_argument("Invalid argument");
        case 2:
            throw std::runtime_error("Runtime error");
        case 3:
            throw 42;
        default:
            std::cout << "Operation completed\n";
    }
}

int main() {
    int option = 2; // Change to 1, 2 or 3 to test each handler.

    try {
        process(option);
    }
    catch (const std::invalid_argument& error) {
        std::cout << "Invalid argument: "
                  << error.what() << '\n';
    }
    catch (const std::runtime_error& error) {
        std::cout << "Runtime error: "
                  << error.what() << '\n';
    }
    catch (int error) {
        std::cout << "Integer exception: "
                  << error << '\n';
    }
    catch (const std::exception& error) {
        // Handles other standard exceptions not caught above.
        std::cout << "Standard exception: "
                  << error.what() << '\n';
    }
    catch (...) {
        // Handles any remaining exception type.
        std::cout << "Unknown exception\n";
    }

    std::cout << "Program continues\n";

    return 0;
}