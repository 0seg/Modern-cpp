/*Returning a Pointer to an Array Element in C++*/

#include <iostream>


const double* find_max_address(const double scores[], size_t count); //Function declaration to find the address of the maximum element in an array

int main(){
    double arr[]{3.5, 7.2, 1.8, 9.4, 5.6, 32.1, 4.9, 2.3, 8.7, 6.1};

    const double* max_ptr = find_max_address(arr, std::size(arr)); //Calling the function to find the address of the maximum element

    std::cout << "The maximum value in the array is: " << *max_ptr << std::endl; //Outputting the maximum value

    return 0;

}


const double* find_max_address(const double scores[], size_t count){
    size_t max_index{};
    double max{};

    for(size_t i{}; i<count; ++i){
        if(scores[i] > max){
            max = scores[i];
            max_index = i;
        }
    }

    return &scores[max_index]; //Returning the address of the maximum element in the array



}