/* Modifying std::string */

#include <iostream>
#include <string>

int main(){


    //Clear : Removes all characters from the string, leaving it with a size of 0.

    std::string str1 {"Hello, World!"};

    std::cout << "str1 is " << str1 << std::endl;
    std::cout << "Size of str1: " << str1.size() << std::endl;
    std::cout << "Capacity of str1: " << str1.capacity() << std::endl;

    str1.clear();

    std::cout << "After clear() str1 is " << str1 << std::endl;
    std::cout << "Size of str1: " << str1.size() << std::endl;
    std::cout << "Capacity of str1: " << str1.capacity() << std::endl;

    //Insert (1): 
    //(1) basic_string& insert(size_type index, size_type count, char ch);
    //Inserts count copies of character ch at index position in the string.

    std::string str2 {"111"};
    std::cout << "str2 is " << str2 << std::endl;

    str2.insert(1, 3, '2'); //Inserts 3 copies of '2' at index 1

    std::cout << "After insert() str2 is " << str2 << std::endl;

    //Insert (2):
    //(2) basic_string& insert(size_type index, const CharT* s)
    // Inserts null-terminateed character string pointed to by s at index position in the string

    std::string str3 {"Hello!"};
    const char* txt3{"  World"};

    std::cout << "str3 is " << str3 << std::endl;

    str3.insert(5, txt3); //Inserts "  World" at index 5

    std::cout << "After insert() str3 is " << str3 << std::endl;

    //Insert (3):
    //(3) basic_string& insert(size_type index, const CharT* s, size_type count)
    //Inserts the characters in the range [s, s+count) at index position in the string

    std::string str4 {"Hello!"};
    const char* txt4{" World Health Organization"};

    std::cout << "str4 is " << str4 << std::endl;

    str4.insert(5, txt4, 6); //Inserts " World" at index 5

    std::cout << "After insert() str4 is " << str4 << std::endl;

    //Insert (4):
    //(4) basic_string& insert(size_type index, const std::string& str)
    //Inserts string str at the position index in the string

    std::string str5 {"Hello!"};
    std::string str6 {" World"};

    std::cout << "str6 is " << str6 << std::endl;

    str6.insert(5, str5); //Inserts " World" at index 5

    std::cout << "After insert() str6 is " << str6 << std::endl;

    //Insert (5):
    //(5) basic_string& insert(size_type index, const std::string& str, size_type index_str, size_type count)
    //Inserts the substring of str that starts at index_str and spans count characters at the position index in the string

    std::string str7 {"Hello!"};
    std::string str8 {"This is a test, world! And this is a test, world!"};

    std::cout << "str7 is " << str7 << std::endl;

    str7.insert(5, str8, 16, 6); //Inserts "world!" at index 5

    std::cout << "After insert() str7 is " << str7 << std::endl;

    //Erase
    //basic_string& erase(size_type index = 0, size_type count = npos);

    std::string str9 {"Hello, World!"};

    str9.erase(5, 7); //Erases 7 characters starting from index 5

    //push_back
    //void push_back(char ch);

    std::string str10 {"Hello, "};
    str10.push_back('W'); //Adds 'W' to the end of the string
    std::cout << "After push_back() str10 is " << str10 << std::endl;

    //pop_back
    //void pop_back();
    str10.pop_back(); //Removes the last character from the string
    std::cout << "After pop_back() str10 is " << str10 << std::endl;

    



}