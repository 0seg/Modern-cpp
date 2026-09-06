/* Size and Capacity of std::string */

#include <iostream>
#include <string>

int main(){
    std::string str1 {"Hello, World!"};
    std::string str2;
    std::string str3{};

    //Empty string

    std::cout << "str1 is empty: " << std::boolalpha << str1.empty() << std::endl;
    std::cout << "str2 is empty: " << std::boolalpha << str2.empty() << std::endl;
    std::cout << "str3 is empty: " << std::boolalpha << str3.empty() << std::endl;

    //Size 

    std::cout << "Size of str1: " << str1.size() << std::endl;
    std::cout << "Size of str2: " << str2.size() << std::endl;
    std::cout << "Size of str3: " << str3.size() << std::endl;

    //max_size: Returns the maximum number of characters that the string can hold

    std::cout << "Max size of str1: " << str1.max_size() << std::endl;

    //Capacity: Returns the size of the storage space currently allocated for the string, expressed in terms of bytes.

    std::cout << "Capacity of str1: " << str1.capacity() << std::endl;

    //Reserve: Requests that the string capacity be at least enough to contain n characters.

    str1.reserve(50);
    std::cout << "Capacity of str1 after reserve(50): " << str1.capacity() << std::endl;

    //shrink_to_fit: Requests the removal of unused capacity.
  
    std::cout << "Capacity of str1 before shrink_to_fit(): " << str1.capacity() << std::endl;

    str1.shrink_to_fit();
    std::cout << "Capacity of str1 after shrink_to_fit(): " << str1.capacity() << std::endl;

    

    return 0;

}