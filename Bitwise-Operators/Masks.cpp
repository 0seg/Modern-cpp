#include <iostream>
#include <bitset>
#include <iomanip>

// This program demonstrates the use of masks in C++

int main(){

    const int COLUMN_WIDTH {20}; // Set the width for displaying columns

    const unsigned char mask_bit_0 {0b00000001}; // Mask for bit 0
    const unsigned char mask_bit_1 {0b00000010}; // Mask for bit 1
    const unsigned char mask_bit_2 {0b00000100}; // Mask for bit 2
    const unsigned char mask_bit_3 {0b00001000}; // Mask for bit 3
    const unsigned char mask_bit_4 {0b00010000}; // Mask for bit 4
    const unsigned char mask_bit_5 {0b00100000}; // Mask for bit 5
    const unsigned char mask_bit_6 {0b01000000}; // Mask for bit 6
    const unsigned char mask_bit_7 {0b10000000}; // Mask for bit 7

    unsigned char value {0b00000000}; // Initialize value with all bits set to 0

    std::cout << std::setw(COLUMN_WIDTH) << "Initial Value: " << std::bitset<8>(value) << std::endl; // Display the initial value in binary


    // Set bit 1 using the mask for bit 1
    value |= mask_bit_1; // Set bit 1 to 1
    std::cout << std::setw(COLUMN_WIDTH) << "After Setting Bit 1: " << std::bitset<8>(value) << std::endl; // Display the value after setting bit 1
    
    // Set bit 7 using the mask for bit 7
    value |= mask_bit_7; // Set bit 7 to 1
    std::cout << std::setw(COLUMN_WIDTH) << "After Setting Bit 7: " << std::bitset<8>(value) << std::endl; // Display the value after setting bit 7

    // Reset bit 1 using the mask for bit 1
    value &= ~mask_bit_1; // Reset bit 1 to 0
    std::cout << std::setw(COLUMN_WIDTH) << "After Resetting Bit 1: " << std::bitset<8>(value) << std::endl; // Display the value after resetting bit 1

    // Reset bit 7 using the mask for bit 7
    value &= ~mask_bit_7; // Reset bit 7 to 0
    std::cout << std::setw(COLUMN_WIDTH) << "After Resetting Bit 7: " << std::bitset<8>(value) << std::endl; // Display the value after resetting bit 7

    // Set all bits using the mask for all bits
    value |= (mask_bit_0 | mask_bit_1 | mask_bit_2 | mask_bit_3 | mask_bit_4 | mask_bit_5 | mask_bit_6 | mask_bit_7); // Set all bits to 1
    std::cout << std::setw(COLUMN_WIDTH) << "After Setting All Bits: " << std::bitset<8>(value) << std::endl; // Display the value after setting all bits

    // Reset bits 0, 2, 4, and 6 using the masks for those bits
    value &= ~(mask_bit_0 | mask_bit_2 | mask_bit_4 | mask_bit_6); // Reset bits 0, 2, 4, and 6 to 0
    std::cout << std::setw(COLUMN_WIDTH) << "After Resetting Bits 0, 2, 4, 6: " << std::bitset<8>(value) << std::endl; // Display the value after resetting bits 0, 2, 4, and 6

    // Toggle bits 1, 3, 5, and 7 using the masks for those bits
    value ^= (mask_bit_1 | mask_bit_3 | mask_bit_5 | mask_bit_7); // Toggle bits 1, 3, 5, and 7
    std::cout << std::setw(COLUMN_WIDTH) << "After Toggling Bits 1, 3, 5, 7: " << std::bitset<8>(value) << std::endl; // Display the value after toggling bits 1, 3, 5, and 7

    

}