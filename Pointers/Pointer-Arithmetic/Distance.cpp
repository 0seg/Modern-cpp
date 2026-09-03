// Distance of two pointers

#include <iostream>
#include <cstddef> // For std::ptrdiff_t

int main(){
    int numbers[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    // Pointer to the first element of the array
    int* ptr1 = numbers + 0;
    // Pointer to the sixth element of the array
    int* ptr2 = numbers + 5;


    std::cout << "Address of ptr1: " << ptr1 << " Value: " << *ptr1 << std::endl; // First element
    std::cout << "Address of ptr2: " << ptr2 << " Value: " << *ptr2 << std::endl; // Sixth element

    // Calculate the distance between the two pointers
    std::ptrdiff_t distance = ptr2 - ptr1; // Distance in terms of number of elements (not bytes)
    std::cout << "Distance between ptr1 and ptr2: " << distance << " elements" << std::endl;

    std::ptrdiff_t reverse_distance = ptr1 - ptr2; // Distance in terms of number of elements (not bytes)
    std::cout << "Distance between ptr2 and ptr1: " << reverse_distance << " elements" << std::endl;

    // Calculate the distance in bytes
    std::ptrdiff_t byte_distance = reinterpret_cast<char*>(ptr2) - reinterpret_cast<char*>(ptr1); // Distance in bytes
    std::cout << "Distance between ptr1 and ptr2 in bytes: " << byte_distance << " bytes" << std::endl;
}