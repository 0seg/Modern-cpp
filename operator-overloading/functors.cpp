/** Functors in C++ */

#include <iostream>

class Adder {
public:
    Adder(int value) : value_(value) {}

    int operator()(int x) const {
        return x + value_;
    }

private:
    int value_;

};

int main() {
    Adder add_five(5);
    int result = add_five(10); // Calls operator() with x = 10
    std::cout << "Result: " << result << std::endl; // Output: Result: 15
    return 0;
}