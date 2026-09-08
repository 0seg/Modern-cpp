/*Type Aliases in C++*/

#include <iostream>


int main(){
    using HugeInt = unsigned long long int; //Type alias for unsigned long long

    HugeInt largeNumber = 12345678901234567890ULL; //Using the type alias to declare a variable

    std::cout << "sizeof(unsigned long long int): " << sizeof(unsigned long long int) << std::endl;
    std::cout << "sizeof(HugeInt): " << sizeof(HugeInt) << std::endl;

    std::cout << "The value of largeNumber is: " << largeNumber << std::endl;


    return 0;
}
    