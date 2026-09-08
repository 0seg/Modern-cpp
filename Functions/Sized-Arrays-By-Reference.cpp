/*
    Sized Arrays by Reference in C++
    */

#include <iostream>


double sum(const double (&arr)[3]){ // Pass the array by reference to avoid decay into a pointer
    double total{};

    for(size_t i{0}; i < std::size(arr); ++i){
        total += arr[i];
    }

    return total;

}

int main(){
    double arr[]{1.1, 2.2, 3.3};

    double result = sum(arr);

    std::cout << "The sum of the array elements is: " << result << std::endl;

}