#include <iostream>
#include <concepts>

// Syntax 1: Concept based on the type
template <typename T>
concept MyIntegral = std::is_integral_v<T>;

template <typename T>
requires MyIntegral<T>
T add(T a, T b) {
    return a + b;
}

// Syntax 2: Concept based on an operation
template <typename T>
concept Multipliable = requires(T a, T b) {
    a * b;
};

template <typename T>
requires Multipliable<T>
T multiply(T a, T b) {
    return a * b;
}

int main() {

    std::cout << add(10, 20) << '\n';

    std::cout << multiply(5, 3) << '\n';

    return 0;
}