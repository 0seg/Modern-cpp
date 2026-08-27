#include <iostream>
#include <bitset>

// This program demonstrates the use of shift operators in C++

int main(){
    unsigned short int value {0xff0u};

    
    std::cout << "Size of short int: " << sizeof(value) << " bytes" << std::endl; // Display the size of short int in bytes
 
    std::cout << "Value: " << std::bitset<16>(value) << ", decimal: " << value << std::endl; // Display the value in binary and decimal

    value = static_cast<unsigned short int>(value << 4); // Left shift the value by 4 bits

    std::cout << "After left shift by 4: " << std::bitset<16>(value) << ", decimal: " << value << std::endl; // Display the new value in binary and decimal


}