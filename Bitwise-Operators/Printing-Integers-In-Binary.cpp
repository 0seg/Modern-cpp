#include <iostream>
#include <bitset>


int main(){
    unsigned short int data = {15};

    std::cout << " data in decimal : " << std::showbase << " " << std::dec << data << std::endl;
    std::cout << " data in octal : " << std::showbase << " " << std::oct << data << std::endl;
    std::cout << " data in hexadecimal : " << std::showbase << " " << std::hex << data << std::endl;
    std::cout << " data in binary : " << std::showbase << " " << std::bitset<16>(data) << std::endl;



    return 0;

}