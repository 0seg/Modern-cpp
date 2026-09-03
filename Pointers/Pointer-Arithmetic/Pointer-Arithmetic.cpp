// Pointer Arithmetic 

#include <iostream>

int main(){
    int numbers[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int* ptr = numbers; // Pointer to the first element of the array

    std::cout << "Values in numbers array using pointer arithmetic:" << std::endl;

    std::cout << "Address : " << ptr << " Value: " << *ptr << std::endl; // First element
    
    // Moves foward by sizeof(int) : 4 bytes
    // Move the pointer to the next element.
    ptr++; // Move to the next element
    std::cout << "Address : " << ptr << " Value: " << *ptr << std::endl; // Second element


    // Also can be *(ptr + 1) to increment the pointer and dereference it in one step
    std::cout << "Address : " << (ptr + 1) << " Value: " << *(ptr + 1) << std::endl; // Third element

    // Move the pointer n steps forward
    std::cout << "Address : " << (ptr + 3) << " Value: " << *(ptr + 3) << std::endl; // Fifth element

    // Can use loop to iterate through the array using pointer arithmetic
    std::cout << "Iterating through the array using pointer arithmetic:" << std::endl;
    for(int i = 0; i < 10; i++){
        std::cout << "Address : " << (ptr + i) << " Value: " << *(ptr + i) << std::endl;
    }


    // Print the values in reverse order using pointer arithmetic
    std::cout << "Values in numbers array in reverse order using pointer arithmetic:" << std::endl;
    for(int i = 9; i >= 0; i--){
        std::cout << "Address : " << (ptr + i) << " Value: " << *(ptr + i) << std::endl;
    }

}