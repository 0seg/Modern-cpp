/**
 * Declaring and using references in C++
 */

#include <iostream>

int main()
{
    int value{42};
    double pi{3.14159};


    // Declare references to existing variables

    int& ref{value};
    double& pi_ref{pi};


    // Access values through variables and references

    std::cout << "Value: " << value << '\n';             // 42
    std::cout << "Reference: " << ref << '\n';           // 42

    std::cout << "Pi: " << pi << '\n';                   // 3.14159
    std::cout << "Pi Reference: " << pi_ref << '\n';     // 3.14159


    // References refer to the same objects

    std::cout << "Address of value: " << &value << '\n';
    std::cout << "Address of ref: " << &ref << '\n';

    std::cout << "Address of pi: " << &pi << '\n';
    std::cout << "Address of pi_ref: " << &pi_ref << '\n';


    // Modify the original objects through their references

    ref = 100;
    pi_ref = 1.61803;


    std::cout << "\nAfter modification:\n";

    std::cout << "Value: " << value << '\n';             // 100
    std::cout << "Reference: " << ref << '\n';           // 100

    std::cout << "Pi: " << pi << '\n';                   // 1.61803
    std::cout << "Pi Reference: " << pi_ref << '\n';     // 1.61803


    // The addresses remain the same

    std::cout << "\nAddresses:\n";

    std::cout << "Address of value: " << &value << '\n';
    std::cout << "Address of ref: " << &ref << '\n';

    std::cout << "Address of pi: " << &pi << '\n';
    std::cout << "Address of pi_ref: " << &pi_ref << '\n';


    return 0;
}