/*Returning by Pointer in C++*/

#include <iostream>

int max_return_ptr(int* a, int* b){
    //This function takes two integer pointers as input and returns a pointer to the maximum integer.
    //The return type is an integer pointer, allowing the caller to modify the returned value directly.

    if(*a > *b) return a;
    else return b;


}

int main(){

    int x{5};
    int y{10};
    int* ptr_max = max_return_ptr(&x, &y); //Pointer
    int val = *ptr_max; //Dereferencing the pointer to get the value

    std::cout << "The maximum value is: " << *ptr_max << std::endl; //Outputting the result
    std::cout << "The maximum value is: " << val << std::endl; //Outputting the result
    std::cout << "x: " << x << ", y: " << y << std::endl; //Outputting the original values

    *ptr_max = 20; //Modifying the maximum value through the pointer

    std::cout << "After modifying ptr_max:" << std::endl;
    std::cout << "The maximum value is: " << *ptr_max << std::endl; //Outputting the modified value
    std::cout << "The maximum value is: " << val << std::endl; //Outputting the copied value   
    std::cout << "x: " << x << ", y: " << y << std::endl; //Outputting the modified values

}