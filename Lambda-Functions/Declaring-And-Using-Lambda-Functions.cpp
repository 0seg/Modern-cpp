/** Declaring and Using Lambda Functions */

#include <iostream>


int main(){

    //Declare a lambda funcion and call ir directly
    [](){
        std::cout << "Hello from Lambda Function!" << std::endl; //Outputting a message from the lambda function
    }(); //Calling the lambda function

    //Lambda function with parameters
    [](int x, int y){
        std::cout << "Sum: " << (x + y) << std::endl; //Outputting the sum of two integers
    }(5, 10); //Calling the lambda function with arguments

    //Calling a lambda function and storing it in a variable
    auto multiply = [](int a, int b){
        return a * b; //Returning the product of two integers
    };
    std::cout << "Product: " << multiply(5, 10) << std::endl; //Outputting the product of two integers

    //Explicitly specifying the return type of a lambda function
    auto divide = [](double a, double b) -> double {
        if(b != 0){
            return a / b; //Returning the quotient of two doubles
        } else {
            std::cerr << "Error: Division by zero!" << std::endl; //Outputting an error message for division by zero
            return 0; //Returning 0 in case of division by zero
        }
    };
    std::cout << "Quotient: " << divide(10.0, 2.0) << std::endl; //Outputting the quotient of two doubles   
    std::cout << "Quotient: " << divide(10.0, 0.0) << std::endl; //Outputting the quotient of two doubles       

    return 0;

}