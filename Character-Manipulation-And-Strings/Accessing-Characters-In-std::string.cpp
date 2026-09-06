/* Accessing Characters in std::string */


#include <iostream>
#include <string>

int main(){

    std::string str1 {"Hello there"};

    //Size of a string : doesn't count the null terminator
    std::cout << "Size of str1: " << str1.size() << std

    //Reading characters in std::string : array index operator
    //Regular indexed loop. 

    for(size_t i{0}; i < str1.size(); ++i){
        std::cout << "str1[" << i << "]: " << str1[i] << std::endl;
    }
    std::cout << std::endl;

    //Can algo use range based for loop 

    std::cout << "Using range based for loop: " << std::endl;

    for(char c : str1){
        std::cout << c << " ";
    }
    std::cout << std::endl;

    //at() syntax to target characters 

    std::cout << "Using at() syntax: " << std::endl;

    for(size_t i{0}; i < str1.size(); ++i){
        std::cout << "str1.at(" << i << "): " << str1.at(i) << std::endl;
    }

    //Modifying with operator[] and at() syntax
    std::cout << "After modification: " << std::endl;

    str1[0] = 'F';
    str1.at(1) = 'E';

    std::cout << "str1: " << str1 << std::endl;

    //Getting the first and last character of a string
    std::string str2 {"Hello World!"};

    char first_char = str2.front();
    char last_char = str2.back();

    std::cout << "First character: " << first_char << std::endl;
    std::cout << "Last character: " << last_char << std::endl;

    //data() function : returns a pointer to the underlying array of characters in the string.
    const char* c_str = str2.data();
    std::cout << "C-style string: " << c_str << std::endl;
    c_str[0] = 'O'; // Modifying the first character of the C-style string
    std::cout << "Modified C-style string: " << c_str << std::endl;
    

}