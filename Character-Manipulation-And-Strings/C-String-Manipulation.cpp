/* C String Manipulation */

#include <iostream>
#include <cstring>

int main(){
    //strlen : Find the length of the string

    const char message[] = {"Hello, World!"};

    //Array decays into pointer when we use const char*

    const char* message2 {"Hello, World!"};

    //strlen ignores the null character at the end of the string
    std::cout << "Length of message: " << strlen(message) << std::endl;

    //Includes the null character
    std::cout << "sizeof message: " << sizeof(message) << std::endl;

    //strlen still works with decayed array
    std::cout << "Length of message2: " << strlen(message2) << std::endl;

    //Print size of pointer
    std::cout << "sizeof message2: " << sizeof(message2) << std::endl;

    //strcmp: Compare two strings 
    //Returns 0 if equal, <0 if first string is less than second, >0 if first string is greater than second
    
    const char* str1 {"AHello"};
    const char* str2 {"BHello"};

    std::cout << "strcmp(str1, str2): " << strcmp(str1, str2) << std::endl;

    //strcmp: Compare n characters of two strings

    std::cout << "strncmp(str1, str2, 1): " << strncmp(str1, str2, 3) << std::endl;


    // Find the first occurrence of a character in a string
    const char* str3 {"Hello, World!"};
    char target {'o'};

    const char* result = str;
    size_t iterations{};


    while((result = strchr(result, target) != nullptr)){
        std::cout << "Found " << target << " at position: " << (result - str3) << std::endl;
        result++;
        iterations++;
    }

    std::cout << "Total iterations: " << iterations << std::endl;

    // Find the last occurrence of a character in a string
    char* str4[] {"Hello, World!"};
    
    char* result2 = strrchr(str4, 'W');

    if(result2){
        std::cout <<  result2+1 << std::endl;//Prints the string starting from the last occurrence of 'W'
    }

    } 