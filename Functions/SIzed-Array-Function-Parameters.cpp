/* Sized Array Function Parameters in C++ */


#include <iostream>
#include <array>

double sum(double arr[3], size_t size){
    //The compiler ignores the size of the1 array in the function parameter. Therefore, the function can accept arrays of any size, but the size must be passed separately.
    double sum{};

    for(size_t i{0}; i < size; ++i){
        sum += arr[i];
    }

    return sum;

}


int main(){

    double arr[]{1.1, 2.2, 3.3, 4.4, 5.5};

    double result = sum(arr, std::size(arr)); // Pass the array and its size to the function

    std::cout << "The sum of the array elements is: " << result << std::endl;


}