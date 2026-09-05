/*
    C String Concatenation and Copy
*/

#include <iostream>
#include <cstring>

int main(){
    char dest[30] = {"Hello, "};
    char src[30] = {"World!"};

    //strcat: Concatenate two strings
    std::strcat(dest, src);
    std::cout << "After strcat: " << dest << std::endl;


    //strncat: Concatenate n characters of two strings
    char dest2[30] = {"Hello, "};
    char src2[30] = {"World!"};
    std::strncat(dest2, src2, 3);
    std::cout << "After strncat: " << dest2 << std::endl;

    //strcpy: Copy one string to another
    const char* src3 {"Hello, World!"};
    char* dest3 = new char[std::strlen(src3) + 1]; // +1 for null terminator

    strcpy(dest3, src3);
    std::cout << "After strcpy: " << dest3 << std::endl;

    delete[] dest3; // Free the allocated memory

    //strncpy: Copy n characters of one string to another
    const char* src4 {"Hello, World!"};
    char dest4[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', '\0'};

    std::cout << "Before strncpy: " << dest4 << std::endl;

    std::strncpy(dest4, src4, 5); // Copy first 5 characters
    std::cout << "After strncpy: " << dest4 << std::endl;

}