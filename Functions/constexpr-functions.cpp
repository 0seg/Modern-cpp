/* constexpr functions in C++ */

#include <iostream>

constexpr double get_value(double x){
    return 3.14 * x;
}


int main(){

    constexpr double result = get_value(5.0); // Call the constexpr function at compile time

    std::cout << "The result of the constexpr function is: " << result << std::endl;

    double runtime_result = get_value(10.0); // Call the constexpr function at runtime  

    std::cout << "The result of the constexpr function at runtime is: " << runtime_result << std::endl;

    

}