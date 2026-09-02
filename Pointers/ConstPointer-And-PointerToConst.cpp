#include <iostream>



int main(){
    

    // Pointer: Can modify the value and the pointer itself

    int* ptr_number = nullptr; // Pointer to an integer, can modify the value and the pointer itself
    int number = 10;

    ptr_number = &number; // Assign the address of number to ptr_number

    std::cout << "Value of number: " << number << std::endl;
    std::cout << "Address of number: " << &number << std::endl;
    std::cout << "Value of ptr_number (address of number): " << ptr_number << std::endl;
    std::cout << "Value pointed to by ptr_number: " << *ptr_number << std::endl;

    // Change the pointed to value 
    *ptr_number = 20; // Modify the value of number through the pointer

    std::cout << "New value of number after modification through pointer: " << number << std::endl; 
    std::cout << "New value pointed to by ptr_number: " << *ptr_number << std::endl;

    // Change the pointer itself to make it point to a new variable
    int new_number = 30;
    ptr_number = &new_number; // Now ptr_number points to new_number

    std::cout << "Value of new_number: " << new_number << std::endl;
    std::cout << "Value of ptr_number (address of new_number): " << ptr_number << std::endl;
    std::cout << "Value pointed to by ptr_number: " << *ptr_number << std::endl;

    // Pointer to const: Can modify the pointer itself but cannot modify the value it points to
    const int* ptr_const = &number; // Pointer to a const integer

    std::cout << "Value of number through ptr_const: " << *ptr_const << std::endl;
    std::cout << "Address of number through ptr_const: " << ptr_const << std::endl;

    *ptr_const = 50; // Error: Cannot modify the value pointed to by ptr_const

    // Change the pointer itself to point to a new variable
    ptr_const = &new_number; // Now ptr_const points to new_number

    std::cout << "Value of new_number through ptr_const: " << *ptr_const << std::endl;
    std::cout << "Address of new_number through ptr_const: " << ptr_const << std::endl;

    // const int* pointer const: Cannot modify the value it points to and cannot modify the pointer itself 

    const int number_const = 100; // A const integer variable
    const int* const ptr_const_const = &number_const; // Pointer to a const integer and the pointer itself is also const
 
    std::cout << "Value of number_const through ptr_const_const: " << *ptr_const_const << std::endl;
    std::cout << "Address of number_const through ptr_const_const: " << ptr_const_const << std::endl;

    *ptr_const_const = 200; // Error: Cannot modify the value pointed to by ptr_const_const
        
    int another_number = 300;
    ptr_const_const = &another_number; // Error: Cannot modify the pointer itself
    std::cout << "Address of another_number through ptr_const_const: " << ptr_const_const << std::endl;

    // int* const pointer: Cannot modify the pointer itself but can modify the value it points to

    int* const ptr_const_pointer = &number; // Pointer to an integer, pointer itself is const

    std::cout << "Value of number through ptr_const_pointer: " << *ptr_const_pointer << std::endl;
    std::cout << "Address of number through ptr_const_pointer: " << ptr_const_pointer << std::endl;

    *ptr_const_pointer = 400; // Modify the value of number through ptr_const_pointer

    std::cout << "New value of number after modification through ptr_const_pointer: " << number << std::endl;

    int yet_another_number = 500;
    ptr_const_pointer = &yet_another_number; // Error: Cannot modify the pointer itself

    
}