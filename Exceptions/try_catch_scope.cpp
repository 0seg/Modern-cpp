/*try and catch in C++*/

#include <iostream>
#include <stdexcept>

int main() {
    int sharedValue = 5;

    try {
        int localValue = 10;

        std::cout << "Local value: " << localValue << '\n';

        throw std::runtime_error("Something went wrong");
    }
    catch (const std::runtime_error& error) {
        std::cout << "Error: " << error.what() << '\n';
        std::cout << "Shared value: " << sharedValue << '\n';
    }

    std::cout << "Program continues.\n";

    return 0;
}