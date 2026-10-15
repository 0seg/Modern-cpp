#include <iostream>
#include "boxcontainer.h"

int main(){

    BoxContainer boxContainer;

    boxContainer.add(10);
    boxContainer.add(20);
    boxContainer.add(30);

    std::cout << "BoxContainer: " << boxContainer << std::endl;

    boxContainer.add(40);
    boxContainer.add(50);

    std::cout << "BoxContainer: " << boxContainer << std::endl;

    for(size_t i{}; i<5; ++i){
        boxContainer.add(i + 100);
    }

    std::cout << "BoxContainer: " << boxContainer << std::endl;

    std::cout << "Removing item 20: " << std::boolalpha << boxContainer.remove_item(20) << std::endl;

    
    for(size_t i{}; i<5; ++i){
        boxContainer.add(10);
    }

    std::cout << "BoxContainer: " << boxContainer << std::endl;

    std::cout << "Removing all items 10: " << boxContainer.remove_all(10) << std::endl;
    
    std::cout << "BoxContainer: " << boxContainer << std::endl;
    
}
