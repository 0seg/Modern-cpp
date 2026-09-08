/*
    Array Function Parameters in C++
    */

#include <iostream>
#include <array> // For std::size




double sum(double arr[], size_t size){
    //When passing an array to a function, the array decays into a pointer to its first element. Therefore, the function receives a pointer to the first element of the array, and the size of the array must be passed separately.

    //std::cout << "sizeof(arr): " << sizeof(arr) << std::endl; // This will print the size of the pointer, not the array
    
    double total{};

    for(size_t i{0}; i < size; ++i){
        total += arr[i];
    }

    return total;

}


int main(){

    double arr[]{1.1, 2.2, 3.3, 4.4, 5.5};


    double result = sum(arr, std::size(arr)); // Pass the array and its size to the function

    std::cout << "The sum of the array elements is: " << result << std::endl;

}