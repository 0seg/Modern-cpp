// Self Tracking Function
//
// The function keeps track of how many times it has been called.
// Each time the function is called, it prints the current call count
// followed by a single space.
//
// Example:
// func();
// func();
// func();
//
// Output:
// 1 2 3 
//
// If the function is called 4 times:
// func();
// func();
// func();
// func();
//
// Output:
// 1 2 3 4 
//
// A static local variable is used so the counter keeps its value
// between function calls while remaining accessible only inside
// this function.
#include <iostream>


void func() {
    static int count = 0;
    count++;
    std::cout << count << " ";
}