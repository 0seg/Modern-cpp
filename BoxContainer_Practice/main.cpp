#include <iostream>
#include "boxcontainer.h"

int main(){

    BoxContainer boxContainer;

    boxContainer.dummy_initialize();

    std::cout << "BoxContainer: " <<boxContainer << std::endl;
    std::cout << "BoxContainer address: " << &boxContainer << std::endl;

    BoxContainer boxContainer2(boxContainer);

    std::cout << "BoxContainer2: " << boxContainer2 << std::endl;
    std::cout << "BoxContainer2 address: " << &boxContainer2 << std::endl;

}