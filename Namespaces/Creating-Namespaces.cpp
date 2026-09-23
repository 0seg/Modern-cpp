#include <iostream>



namespace LessOne{

    int add(int x, int y){
        return x + y - 1;
    }
}

namespace PlusOne{

    int add(int x, int y){
        return x + y + 1;
    }

}


int main(){

    int resultLessOne =  LessOne::add(5,5);

    int resultPlusOne = PlusOne::add(5,5);


    std::cout << "LessOne -> Result " << resultLessOne << std::endl;

    std::cout << "PlusOne -> Result " << resultPlusOne << std::endl;

    
    
}