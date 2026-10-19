#include <iostream>

// Generic alias for function pointers.
template <typename ReturnType, typename... Args>
using FunctionPtr = ReturnType (*)(Args...);

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

double square(double value) {
    return value * value;
}

int main() {
    // Function pointer returning int and accepting two ints.
    FunctionPtr<int, int, int> operation = add;
    std::cout << operation(3, 4) << '\n'; // 7

    // Change the function while keeping the same signature.
    operation = multiply;
    std::cout << operation(3, 4) << '\n'; // 12

    // Function pointer returning double and accepting one double.
    FunctionPtr<double, double> unaryOperation = square;
    std::cout << unaryOperation(5.0) << '\n'; // 25

    return 0;
}