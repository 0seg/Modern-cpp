/** Capture All Lists in Lambda Functions */


#include <iostream>

int main(){

    int x{5};
    int y{10};
    int z{15};


    // Capturing copies of all variables by value using [=]
    auto func = [=](){
        std::cout << "Sum of x, y, z (captured by value): " << (x + y + z) << std::endl; // Output the sum of x, y, and z
    };

    func();

    // Capturing references to all variables using [&]
    auto func2 = [&](){
        x += 5; // Modify the original variable x in the main function
        y += 10; // Modify the original variable y in the main function
        z += 15; // Modify the original variable z in the main function
        std::cout << "Modified values of x, y, z (captured by reference): " << x << ", " << y << ", " << z << std::endl; // Output the modified values of x, y, and z
    };

    func2();

    return 0;
}