/**
 * Dangling Pointers in C++
 *
 * A dangling pointer is a pointer that refers to an object
 * that no longer exists.
 *
 * Dereferencing a dangling pointer results in Undefined Behavior.
 */

#include <iostream>

int main()
{
    // -------------------------------------------------
    // Case 1: Uninitialized pointer
    // -------------------------------------------------

    // This is NOT technically a dangling pointer.
    // It contains an indeterminate value and does not point
    // to a known valid object.

    int* ptr;

    // *ptr = 42; // Undefined Behavior


    // -------------------------------------------------
    // Case 2: Pointer becomes dangling after delete
    // -------------------------------------------------

    int* ptr2{ new int{42} };

    std::cout << "Value: " << *ptr2 << '\n';

    delete ptr2;

    // ptr2 is now a dangling pointer.

    // std::cout << *ptr2 << '\n'; // Undefined Behavior


    // -------------------------------------------------
    // Case 3: Multiple pointers to the same object
    // -------------------------------------------------

    int* ptr3{ new int{100} };
    int* ptr4{ ptr3 };

    // Both pointers refer to the same dynamically allocated object.

    std::cout << "ptr3: " << *ptr3 << '\n';
    std::cout << "ptr4: " << *ptr4 << '\n';

    delete ptr3;

    // The dynamically allocated object no longer exists.
    // Both ptr3 and ptr4 are now dangling pointers.

    // std::cout << *ptr3 << '\n'; // Undefined Behavior
    // std::cout << *ptr4 << '\n'; // Undefined Behavior


    // -------------------------------------------------
    // Setting a pointer to nullptr after delete
    // -------------------------------------------------

    int* ptr5{ new int{200} };

    std::cout << "Value: " << *ptr5 << '\n';

    delete ptr5;

    ptr5 = nullptr;

    // ptr5 is now in a known state and can be checked safely.

    if (ptr5 != nullptr)
    {
        std::cout << *ptr5 << '\n';
    }
    else
    {
        std::cout << "Pointer is nullptr, cannot dereference.\n";
    }


    // -------------------------------------------------
    // Important: nullptr only affects one pointer
    // -------------------------------------------------

    int* ptr6{ new int{300} };
    int* ptr7{ ptr6 };

    delete ptr6;

    ptr6 = nullptr;

    // ptr7 is STILL a dangling pointer.
    // Setting ptr6 to nullptr does not modify ptr7.

    // std::cout << *ptr7 << '\n'; // Undefined Behavior

    ptr7 = nullptr;


    return 0;
}