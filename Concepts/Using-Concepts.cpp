/* Using Concepts in C++ */

#include <iostream>
#include <concepts>

//Syntax 1:
template <typename T>
requires std::integral<T> // Using the integral concept to restrict the template parameter to integral types
T add(T a, T b) {
    return a + b;
}

//Syntax 2:
template <std::integral T> // Using the integral concept to restrict the template parameter to integral types
T add2(T a, T b) {
    return a + b;
}

//Syntax 3:
auto add3(std::integral auto a, std::integral auto b) { // Using the integral concept to restrict the function parameters to integral types
    return a + b;
}

//Syntax 4:

template <typename T>
T add4(T a, T b) requires std::integral<T> { // Using the integral concept to restrict the template parameter to integral types
    return a + b;
}



int main(){

    // Testing the add function with integral types
    int x{10};
    int y{20};

    auto result = add(x, y);

    std::cout << "Sum of " << x << " and " << y << " is: " << result << std::endl;

    // Testing the add function with other integral types
    char c1{'A'};
    char c2{'B'};

    auto result2 = add(c1, c2);

    std::cout << "Sum of '" << c1 << "' and '" << c2 << "' is: '" << result2 << "'" << std::endl;

    // Testing the add function with non-integral types (this will cause a compilation error)
    
    // double d1{10.5};
    // double d2{20.5};

    //auto result3 = add(d1, d2); // This line will cause a compilation error because double is not an integral type

    //std::cout << "Attempting to add non-integral types will result in a compilation error." << std::endl;

    return 0;


}