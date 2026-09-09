/** Overloading with Pointer Parameters */

#include <iostream>

double max(double* numbers, size_t size){
    double max_value{0}; // Initialize max_value with the first element

    for(size_t i{0}; i < size; ++i){
        if(numbers[i] > max_value){ // Compare using pointer arithmetic
            max_value = numbers[i];
        }
    }
    return max_value;
}

int max(int* numbers, size_t size){
    int max_value{0}; // Initialize max_value with the first element

    for(size_t i{0}; i < size; ++i){
        if(numbers[i] > max_value){ // Compare using pointer arithmetic
            max_value = numbers[i];
        }
    }
    return max_value;
}

int main(){

    double double_numbers[]{1.5, 3.2, 0.8, 4.1, 2.9};
    int int_numbers[]{5, 2, 9, 1, 6};

    // Call the overloaded max function for double array
    // auto result = max(double_numbers, std::size(double_numbers));

    
    // Call the overloaded max function for int array
    // auto result = max(int_numbers, std::size(int_numbers));


    return 0;
}