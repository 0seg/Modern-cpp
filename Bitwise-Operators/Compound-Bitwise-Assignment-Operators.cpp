#include <iostream>
#include <bitset>
#include <iomanip>




int main(){
    const int COLUMN_WIDTH {20}; // Set the width for displaying columns

    unsigned char value {0b00110100}; // Initialize value1 with a binary literal


    // Display the original value in binary
    std::cout << std::setw(COLUMN_WIDTH) << "Original Value: " << std::bitset<8>(value) << std::endl;

    // Compund left shift assignment operator

    std::cout << std::setw(COLUMN_WIDTH) << "Left Shift Assignment: " << std::bitset<8>(value <<= 2) << std::endl; // Left shift the value by 2 bits and display the result in binary

    // Compound right shift assignment operator

    std::cout << std::setw(COLUMN_WIDTH) << "Right Shift Assignment: " << std::bitset<8>(value >>= 1) << std::endl; // Right shift the value by 1 bit and display the result in binary

    // Compound OR assignment operator
    
    std::cout << std::setw(COLUMN_WIDTH) << "OR Assignment: " << std::bitset<8>(value |= 0b00001111) << std::endl; // Perform OR operation with 0b00001111 and display the result in binary

    // Compound AND assignment operator

    std::cout << std::setw(COLUMN_WIDTH) << "AND Assignment: " << std::bitset<8>(value &= 0b11110000) << std::endl; // Perform AND operation with 0b11110000 and display the result in binary

    // Compound XOR assignment operator

    std::cout << std::setw(COLUMN_WIDTH) << "XOR Assignment: " << std::bitset<8>(value ^= 0b00001111) << std::endl; // Perform XOR operation with 0b00001111 and display the result in binary

    // 

}
