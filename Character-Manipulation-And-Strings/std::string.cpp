/* std::string */

#include <iostream>
#include <string>

int main(){
    std::string str1; //Empty string
    std::string planet {"Earth"}; //String initialized with string literal
    std::string str_planet {planet}; //String initialized with another string
    std::string message {"Hello, World!", 5}; //Initialize with part of string literal

    std::string str2(10, 'x'); //String initialized with 10 copies of 'x'

    std::string str3{"Hello, World!"}; //String initialized with string literal
    std:: string str4{str3, 6, 5}; //Initialize with part of an existing string


    std::cout << "str1: " << str1 << std::endl;
    std::cout << "planet: " << planet << std::endl;
    std::cout << "str_planet: " << str_planet << std::endl
    std::cout << "message: " << message << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;
    std::cout << "str4: " << str4 << std::endl;


}