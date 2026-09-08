/*Returning by Reference in C++*/

#include <iostream>

int& max_return_ref(int& a, int& b){
    //This function takes two integer references as input and returns a reference to the maximum integer.
    //The return type is an integer reference, allowing the caller to modify the returned value directly.

    if(a > b) return a;
    else return b;


}


int main(){

    int x{5};
    int y{10};
    int& ref_max = vmax_return_ref(x, y); //Reference
    int val = ref_max; //Copy

    std::cout << "The maximum value is: " << ref_max << std::endl; //Outputting the result
    std::cout << "The maximum value is: " << val << std::endl; //Outputting the result
    std::cout << "x: " << x << ", y: " << y << std::endl; //Outputting the original values

    ref_max = 20; //Modifying the maximum value through the reference

    std::cout << "After modifying ref_max:" << std::endl;
    std::cout << "The maximum value is: " << ref_max << std::endl; //Outputting the modified value
    std::cout << "The maximum value is: " << val << std::endl; //Outputting the copied value   
    std::cout << "x: " << x << ", y: " << y << std::endl; //Outputting the modified values
    
    





}