#include <iostream>

// Define an alias for a function pointer.
using Operation = int (*)(int, int);

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int calculate(int a, int b, Operation operation) {
    return operation(a, b);
}

int main() {
    std::cout << calculate(3, 4, add) << '\n';      // 7
    std::cout << calculate(3, 4, multiply) << '\n';  // 12

    return 0;
}