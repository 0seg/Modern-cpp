#include <iostream>
#include "compare.h" // Include the header file for the max function

int main() {
    int a = 10;
    int b = 20;

    // Call the max function from compare.cpp
    int maximum = max(a, b);

    std::cout << "The maximum value between " << a << " and " << b << " is: " << maximum << std::endl;

    // Call the min function from compare.cpp
    int minimum = min(a, b);

    std::cout << "The minimum value between " << a << " and " << b << " is: " << minimum << std::endl;

    return 0;
}