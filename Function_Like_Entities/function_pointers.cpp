/* Function Pointers in C++ */

#include <iostream>

int add(int a, int b) {
    return a + b;
}


int main(){


    // Declare a function pointer and assign it to the 'add' function
    int (*funcPtr)(int, int) = &add;

    // Use the function pointer to call the function
    int result = funcPtr(5, 3);
    std::cout << "Result of addition: " << result << std::endl;



    return 0;

}