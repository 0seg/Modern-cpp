/*
Template Specialization in C++
*/

#include <iostream>
#include <cstring>


template <typename T> T maximum(T a, T b) {
    return (a > b) ? a : b;
}

template <> //Template specialization for const char*
const char* maximum<const char*>(const char* a, const char* b) {
    return (std::strcmp(a, b) > 0) ? a : b;
}


int main(){
    const char* str1 = "Hello";
    const char* str2 = "World";

    const char* result = maximum<const char*>(str1, str2); // Using the specialized version for const char*

    std::cout << "Maximum of \"" << str1 << "\" and \"" << str2 << "\" is: \"" << result << "\"" << std::endl;

    return 0;

}