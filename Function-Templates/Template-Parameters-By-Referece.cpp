/*Template Parameters by Reference*/


#include <iostream>

//Declaration of the function template


template <typename T> const T& maximum(const T& a, const T& b);




int main(){

    unsigned int x{10};
    unsigned int y{20};

    std::cout << "Direcction of x: " << &x << std::endl;
    std::cout << "Direcction of y: " << &y << std::endl;

    const unsigned int& result1 = maximum(x, y); // Passing arguments by reference

    std::cout << "Maximum of " << x << " and " << y << " is: " << result1 << std::endl;

    return 0;
}



// Definition of the function template
template <typename T> const T& maximum(const T& a, const T& b) {
    return (a > b) ? a : b;
}
