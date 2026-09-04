/**
 * Comparing Pointers and References in C++
 */

#include <iostream>

int main()
{
    // Declare a variable, reference, and pointer

    double value{3.14159};

    double& ref_value{value};  // Reference to value
    double* ptr_value{&value}; // Pointer to value


    // Reading

    std::cout << "Value: " << value << '\n';                   // 3.14159
    std::cout << "Reference: " << ref_value << '\n';           // 3.14159
    std::cout << "Pointer: " << *ptr_value << '\n';            // 3.14159
    std::cout << "Pointer Address: " << ptr_value << '\n';     // Address of value


    // Writing through pointer

    *ptr_value = 2.71828; // Modify value through pointer

    std::cout << "\nAfter modifying through pointer:\n";

    std::cout << "Value: " << value << '\n';                   // 2.71828
    std::cout << "Reference: " << ref_value << '\n';           // 2.71828
    std::cout << "Pointer: " << *ptr_value << '\n';            // 2.71828


    // Writing through reference

    ref_value = 1.61803; // Modify value through reference

    std::cout << "\nAfter modifying through reference:\n";

    std::cout << "Value: " << value << '\n';                   // 1.61803
    std::cout << "Reference: " << ref_value << '\n';           // 1.61803
    std::cout << "Pointer: " << *ptr_value << '\n';            // 1.61803


    return 0;
}