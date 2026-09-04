/**
 * Memory-Leak.cpp
 *
 * This file demonstrates common memory leak scenarios in C++.
 *
 * A memory leak occurs when dynamically allocated memory is no longer
 * accessible but has not been released, reducing the available memory
 * during the program's execution.
 */

#include <iostream>

int main()
{
    // Allocate memory for an integer on the heap

    int* ptr{ new int{42} };

    int value{100}; // Some other variable


    // Use the dynamically allocated memory

    std::cout << "Value: " << *ptr << '\n';


    // Forgetting to delete dynamically allocated memory causes a memory leak

    // delete ptr; // Uncommenting this line would prevent the memory leak

    delete ptr; // Release the dynamically allocated memory


    // Reassigning ptr after releasing the previous allocation

    ptr = &value;


    // Double allocation without releasing the previous memory

    int* ptr2{ new int{200} };

    ptr2 = new int{300}; // The address of the first allocation is lost

    // The first allocated int can no longer be deleted -> memory leak


    // Nested scope causing a memory leak

    {
        int* ptr3{ new int{400} };

        // ptr3 goes out of scope, but the dynamically allocated
        // memory remains allocated.
    }


    return 0;
}