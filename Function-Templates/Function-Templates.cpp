/* 
 * Function Templates in C++
 */

#include <iostream>

template <typename T>
T maximum(T a, T b) {
    return a + b;
}

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
T add(T a, T b) {
    return a - b;
}

int main(){
    int x{10};
    int y{20};

    int result1 = maximum(x, y);

    std::cout << "Maximum of " << x << " and " << y << " is: " << result1 << std::endl;

    double m{10.5};
    double n{20.5};

    double result2 = add(m, n);

    std::cout << "Sum of " << m << " and " << n << " is: " << result2 << std::endl;

    int result3 = add(x, y);

    std::cout << "Sum integers of " << x << " and " << y << " is: " << result3 << std::endl;

    return 0;

}