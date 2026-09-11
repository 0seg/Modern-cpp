/* Decltype and Auto in C++ */


#include <iostream>




// decltype(auto) is used to deduce the return type of the function based on the types of the arguments passed to it. It allows for more flexibility in handling different types of arguments, including mixed types.
template <typename T, typename F>
decltype(auto) maximum(T a, F b) {
    return (a > b) ? a : b;
}



int main() {

    int x{10};
    double y{20.5};

    auto result1 = maximum(x, y); // Using decltype(auto) to deduce the return type based on the types of x and y

    std::cout << "Maximum of " << x << " and " << y << " is: " << result1 << std::endl;
    std::cout << "sizeof(result1): " << sizeof(result1) << std::endl; // Displaying the size of the result

    int r{30};
    double s{15.5};

    auto result2 = maximum(r, s); // Using decltype(auto) to deduce the return type based on the types of r and s

    std::cout << "Maximum of " << r << " and " << s << " is: " << result2 << std::endl;
    std::cout << "sizeof(result2): " << sizeof(result2) << std::endl; // Displaying the size of the result

    return 0;

}
