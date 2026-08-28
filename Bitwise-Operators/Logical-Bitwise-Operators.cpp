// This program demonstrates the use of logical and bitwise operators in C++

#include <iostream>
#include <bitset>
#include <iomanip>


int main(){
    int COLUMN_WIDTH {20}; // Set the width for displaying columns
    unsigned char value1 {00000011};
    unsigned char value2 {00000101};

    std::cout << std::setw(COLUMN_WIDTH) << "Value 1: " << std::bitset<8>(value1) << std::endl; // Display value1 in binary and decimal

    std::cout << std::setw(COLUMN_WIDTH) << "Value 2: " << std::bitset<8>(value2) << std::endl; // Display value2 in binary and decimal

    // AND operator

    std::cout << std::setw(COLUMN_WIDTH) << "AND: " << std::bitset<8>(value1 & value2) << std::endl; // Display the result of AND operation in binary


    // OR operator

    std::cout << std::setw(COLUMN_WIDTH) << "OR: " << std::bitset<8>(value1 | value2) << std::endl; // Display the result of OR operation in binary

    // XOR operator

    std::cout << std::setw(COLUMN_WIDTH) << "XOR: " << std::bitset<8>(value1 ^ value2) << std::endl; // Display the result of XOR operation in binary

    // NOT operator

    std::cout << std::setw(COLUMN_WIDTH) << "NOT: " << std::bitset<8>(~value1) << std::endl; // Display the result of NOT operation in binary
    std::cout << std::setw(COLUMN_WIDTH) << "NOT: " << std::bitset<8>(~value2) << std::endl; // Display the result of NOT operation in binary

    return 0;
}