/*
    Demonstrates the use of std::string::compare() method.
*/

#include <iostream>
#include <string>

int main(){

    //Compare(1)
    //int compare(const basic_string& str) const noexcept;(1)

    std::string str1 {"Hello"};
    std::string str2 {"World"};


    std:cout << "str1 : " << str1 << std::endl;
    std::cout << "str2 : " << str2 << std::endl;
    std::cout << "Comparing str1 and str2: " << str1.compare(str2) << std::endl;
    std::cout << "Comparing str2 and str1: " << str2.compare(str1) << std::endl;


    //Compare(2)
    //int compare( size_type pos1, size_type count1, const basic_string& str) const;(2)
    //Compares a substring of this string(from pos1, going count1 position) to str.

    std::string str3 {"Hello, World!"};

    std::cout << "Comparing 'World' to 'Hello' : " << str3.compare(6, 5, str1) << std::endl;

    //Compare(3)
    //int compare( const CharT* s) const;(4)
    //Compares this string to the null-terminated character sequence beginning 
    // at the character pointed to by s.

    std::string str5{"Hello"};
    const char* message{"World"};
    std::cout << "Comparing Hello to World: " << str5.compare(message) << std::endl;
    std::cout << "Comparing World to Hello: " << str5.compare("World") << std::endl; //Directly passing string literal

    


    return 0;

}
