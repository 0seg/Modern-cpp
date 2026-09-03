/*
Finding Nemo: The Little Guy!

Given an array of integers, find the memory address of the smallest
element in the array (Nemo).

Store the address of the smallest element in the pre-declared pointer
variable `min_address`.

Important:
- Use pointer arithmetic to access the array elements.
- Array index notation such as data[i] or data[1] is not allowed.
- The goal is to store the address of the smallest element, not its value.

Example:
    int data[] {11, 2, 52, 53, 9, 13, 5, 7, 12, 11};

The smallest element is 2, so `min_address` should point to its
memory location.
*/

#include <iostream>

int main(){
    int data[] {11, 2, 52, 53, 9, 13, 5, 7, 12, 11};

    int* min_address = nullptr; // Pointer to store the address of the smallest element


    for(int i = 0; i < 10; ++i) {
        if (min_address == nullptr || *(data + i) < *min_address) {
            min_address = data + i; // Update min_address to point to the smallest element found so far
        }
    }

    if (min_address != nullptr) {
        std::cout << "Address of the smallest element: " << min_address << std::endl;
        std::cout << "Value of the smallest element: " << *min_address << std::endl;
    }

}