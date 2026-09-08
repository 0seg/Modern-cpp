/* Input and Output Parameters in C++ */

#include <iostream>
#include <string>

void max_str(const std::string& input1, const std::string& input2, std::string& output) {
    //This function takes two input strings and returns the maximum string based on lexicographical order through the output parameter.
    //The variable 'output' is passed by reference, allowing the function to modify its value directly.

    if (input1 > input2) {
        output = input1;
    } else {
        output = input2;
    }
}

void max_double(double input1, double input2, double* output) {
    //This function takes two input doubles and returns the maximum double through the output parameter.
    //The variable 'output' is a pointer, allowing the function to modify its value directly.

    if (input1 > input2) {
        *output = input1;
    } else {
        *output = input2;
    }
}



int main(){
    
    //Exaple usage max_str function, using reference parameter to return the maximum string
    /*
    std::string str1, str2, maxString;
    str1{"apple"};
    str2{"banana"};
    max_str(str1, str2, maxString); //Calling the function with input strings and output parameter

    std::cout << "The maximum string is: " << maxString << std::endl; //Outputting the result
    */


    
    //Example usage max_double function, using pointer parameter to return the maximum double

    /*
    double num1, num2, maxNum;
    num1 = 3.14;
    num2 = 2.71;
    max_double(num1, num2, &maxNum); //Calling the function with input doubles and output parameter

    std::cout << "The maximum number is: " << maxNum << std::endl; //Outputting the result
    
    */



}