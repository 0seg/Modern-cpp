#include <iostream>
#include <utility>

// Accepts an lvalue.
void classify(int& value) {
    std::cout << "Lvalue: " << value << '\n';
}

// Accepts an rvalue.
void classify(int&& value) {
    std::cout << "Rvalue: " << value << '\n';
}

int main() {
    int x = 10;

    classify(x);            // x is an lvalue
    classify(x + 5);        // x + 5 is an rvalue
    classify(20);           // 20 is an rvalue
    classify(std::move(x)); // Treats x as an rvalue

    return 0;
}