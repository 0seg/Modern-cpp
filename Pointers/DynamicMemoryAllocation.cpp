// Dynamic Memory Allocation in C++

#include <iostream>

int main()
{
    // BAD: Dereferencing an uninitialized pointer

    int* ptr; // Does not point to a valid object

    // *ptr = 42; // Undefined Behavior


    // GOOD: Dynamically allocate and initialize an int

    int* ptr2{ new int{42} };

    // Use the pointer to access the dynamically allocated object

    std::cout << "Value: " << *ptr2 << '\n';

    // Release the dynamically allocated memory

    delete ptr2;


    // BAD: Calling delete twice on the same pointer

    int* ptr3{ new int{100} };

    delete ptr3;

    // delete ptr3; // Undefined Behavior: double delete


    return 0;
}