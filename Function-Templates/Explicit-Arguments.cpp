/* Explicit Template Arguments in C++ */

#include <iostream>

template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int main(){
    int x{10};
    int y{20};

    int result1 = maximum<int>(x, y); // Explicitly specifying the template argument as int

    std::cout << "Maximum of " << x << " and " << y << " is: " << result1 << std::endl;

    double m{10.5};
    double n{20.5};

    double result2 = maximum<double>(m, n); // Explicitly specifying the template argument as double

    std::cout << "Maximum of " << m << " and " << n << " is: " << result2 << std::endl;

    return 0;



}