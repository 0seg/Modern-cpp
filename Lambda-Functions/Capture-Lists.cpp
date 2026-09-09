/** Capture Lists in Lambda Functions */

#include <iostream>

int main(){
    
    //Capture lists 
    int x{5};
    int y{10};

    auto func = [x, y](){
        std::cout << "Inside lambda function: x = " << x << ", y = " << y << std::endl; // This will cause a compilation error because x and y are not captured
    };

    func(); // Call the lambda function

    // Capture by value
    int z{15};
    auto func2 = [z](){
        //this variable is a copy, not affecting the original variable z in the main function
        std::cout << "Inside lambda function: z = " << z << std::endl; // This will work because z is captured by value
    };

    func2(); // Call the lambda function

    // Capture by reference
    int a{20};
    auto func3 = [&a](){
        a += 5; // Modify the original variable a in the main function
        std::cout << "Inside lambda function: a = " << a << std::endl; // This will work because a is captured by reference
    };

    func3(); // Call the lambda function

    return 0;
}