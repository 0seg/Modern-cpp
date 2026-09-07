/* Functions in C++ */

#include <iostream>

//Function that takes a single parameter

void enter_bar(unsigned int age){
    if(age >= 18){
        std::cout << "Welcome to the bar!" << std::endl;
    } else {
        std::cout << "Sorry, you are not old enough to enter the bar." << std::endl;
    }
}

//Function that takes multiple parameters and return a value

int max(int a, int b){
    // Compare two integers and return the maximum
    if(a > b){
        return a;
    } else {
        return b;
    }
}

//Function that doesn't take any parameters and doesn't return a value

void say_hello(){
    std::cout << "Hello, World!" << std::endl;
}

//Function that takes no parameters but returns a value

int get_five(){
    return 5;
}



int main(){

    std::cout << "First function: Checking age to enter the bar" << std::endl;
    enter_bar(20); // Call the function with an age of 20
    enter_bar(15); // Call the function with an age of 15

    std::cout << "Second function: Finding the maximum of two numbers" << std::endl;
    int result = max(10, 20); // Call the function with two integers
    std::cout << "The maximum value is: " << result << std::endl;

    std::cout << "Third function: Saying hello" << std::endl;
    say_hello(); // Call the function to say hello

    std::cout << "Fourth function: Getting the value five" << std::endl;
    int five = get_five(); // Call the function to get the value five
    std::cout << "The value returned is: " << five << std::endl;
    

    return 0;

}