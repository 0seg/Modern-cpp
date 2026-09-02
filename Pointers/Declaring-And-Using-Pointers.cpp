#include <iostream>

int main(){


    // Declaring a pointer variable
    int* ptr = nullptr; // Initialize pointer to null




    //Initializing a pointer to point to an integer variable
    int num = 42;
    ptr = &num; // Assign the address of num to ptr

    std::cout << "Value of num: " << num << std::endl;
    std::cout << "Address of num: " << &num << std::endl;
    std::cout << "Value of ptr (address of num): " << ptr << std::endl;
    std::cout << "Value pointed to by ptr: " << *ptr << std::endl;

}