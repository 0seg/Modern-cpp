/* consteval functions in C++ */


#include <iostream>

consteval int get_value(int x){
    return 3 * x;
}

int main(){
    
    int val1 = get_value(5); // Call the consteval function at compile time.

    std::cout << "The result of the consteval function is: " << val1 << std::endl;

    int f{3};

    //int val2 = get_value(f); //Compiler error: consteval function 'get_value' cannot be called with a non-constant argument

    return 0;

}