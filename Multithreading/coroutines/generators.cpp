
#include <generator>
#include <iostream>

// Generates even numbers up to the given limit.
std::generator<int> even_numbers(int limit) {
    for (int i = 2; i <= limit; i += 2) {
        co_yield i;
    }
}

int main() {
    std::cout << "Even numbers:\n";

    for (int number : even_numbers(10)) {
        std::cout << number << '\n';
    }

    return 0;
}
