/*
    Demonstrates the use of std::string methods for replacing, copying, resizing, and swapping.
*/


#include <iostream>
#include <string>

int main(){

    //Replacing(1)
    //basic_string& replace(size_type pos, size_type count, const basic_string& str);
    //Replace the range [pos, pos+count) with str. 
    
    std::string str1{"Finding Nemo"};
    std::string str2{"Searching for"};
    std::cout << "str1 : " << str1 << std::endl;

    std::cout <<"Replacing 'Finding' with 'Searching for' in str1" << std::endl;
    str1.replace(0, 7, str2); //Replace "Finding" with

    std::cout << "After replace() str1 : " << str1 << std::endl;

    //Replacing(2)
    //basic_string$ replace(size_type pos, size_type count, const basic_string& str, size_type pos2, size_type count2 = npos);
    //Replace in part of str, not its entirety.
    
    std::string str3{"Finding Nemo"};
    std::string str4{"The horse was found in the fields searching for food."};

    std::cout << "str3 : " << str3 << std::endl;

    std::cout << "Replacing 'Finding' in str3 with 'Searching for' from str4" << std::endl;
    str3.replace(0, 7, str4, 34, 13);

    std::cout << "After replace() str3 : " << str3 << std::endl;

    //Copying
    //size_type copy(char* dest, size_type count, size_type pos = 0);
    //Copy a subsection of *this string to dest. Dest is pre-allocated
    //The resulting character string is not null-terminated. Be careful

    std::string str5{"My name is Bond, James Bond."};
    char txt[25]{};

    std::cout << "std::size(txt)": << std::size(txt) << std::endl;
    std::cout << "str5 : " << str5 << std::endl;
    
    std::cout << "Copying 15 characters from str5 to txt" << std::endl;
    str5.copy(txt, 15, 5); //Copy 15 characters from str5 starting at index 5

    std::cout << "After copy() txt : " << txt << std::endl;

    //Resizing
    //std::resize();

    std::string str6{"Hello"};

    std::cout << "null char : " << '\0' << std::endl;
    std::cout << "str6 : " << str6 << std::endl;
    std::cout << "size of str6 : " << str6.size() << std::endl;
    std::cout << "capacity of str6 : " << str6.capacity() << std::endl;

    std::cout << "Resizing str6 to 10 characters" << std::endl;
    str6.resize(10); //Resize to 10 characters, adding null characters

    std::cout << "str6 : " << str6 << std::endl;
    std::cout << "size of str6 : " << str6.size() << std::endl;
    std::cout << "capacity of str6 : " << str6.capacity() << std::endl;

    //Prove that they are indeed null characters 

    std::cout << "Printing each character in str6 with its index" << std::endl;
    for(size_t i{0}; i < str6.size(); ++i){
        std::cout << "str6[" << i << "] : " << str6[i] << std::endl;
    }

    //Resize with fill character
    str6.resize(15, 'x'); //Resize to 15 characters, adding 'x' characters

    std::cout << "str6 : " << str6 << std::endl;
    std::cout << "size of str6 : " << str6.size() << std::endl;
    std::cout << "capacity of str6 : " << str6.capacity() << std::endl;


    //Swapping

    std::string str7{"Hello"};
    std::string str8{"World"};

    //Before swap
    std::cout << "Before swap() str7 : " << str7 << std::endl;
    std::cout << "Before swap() str8 : " << str8 << std::endl;
    std::cout << "Before swap() str7.size() : " << str7.size() << std::endl;
    std::cout << "Before swap() str7.capacity() : " << str7.capacity() << std::endl;
    std::cout << "Before swap() str8.size() : " << str8.size() << std::endl;
    std::cout << "Before swap() str8.capacity() : " << str8.capacity() << std::endl;

    std::cout << "Swapping str7 and str8" << std::endl;
    str7.swap(str8);

    //After swap
    std::cout << "After swap() str7 : " << str7 << std::endl;
    std::cout << "After swap() str8 : " << str8 << std::endl;
    std::cout << "After swap() str7.size() : " << str7.size() << std::endl;
    std::cout << "After swap() str7.capacity() : " << str7.capacity() << std::endl;
    std::cout << "After swap() str8.size() : " << str8.size() << std::endl;
    std::cout << "After swap() str8.capacity() : " << str8.capacity() << std::endl;

}