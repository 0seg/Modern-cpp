/** Overloading with Const Reference Parameters */

#include <iostream>


int max(int& x, int& y){

    x += 10; // Modify the first integer by adding 10
 
    return (x > y) ? x : y; // Return the maximum of two integers
}

int max(const int& x, const int& y){

    // x += 10; // This line would cause a compilation error because x is a const reference

    return (x > y) ? x : y; // Return the maximum of two integers
}

int main(){

    int a{5};
    int b{10};

    // Call the overloaded max function for non-const references
    int result1 = max(a, b);
    std::cout << "Max of a and b (non-const): " << result1 << std::endl; // Output: Max of a and b (non-const):

    // Call the overloaded max function for const references
    const int c{15};
    const int d{20};
    int result2 = max(c, d);
    std::cout << "Max of c and d (const): " << result2 << std::endl; // Output: Max of c and d (const):

    



    return 0;

}