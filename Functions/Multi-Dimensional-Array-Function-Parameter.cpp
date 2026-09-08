/* Multi-Dimensional Array Function Parameters in C++ */

#include <iostream>


//Declarations
double sum_2d(const double arr[][3], size_t size);
double sum_3d(const double arr[][3][2], size_t size1, size_t size2);



int main(){
    double arr_2d[][3]{{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}, {7.7, 8.8, 9.9}};

    double arr_3d[][3][2]{{{1.1, 2.2}, {3.3, 4.4}, {5.5, 6.6}}, {{7.7, 8.8}, {9.9, 10.10}, {11.11, 12.12}}};

    double result_2d = sum_2d(arr_2d, std::size(arr_2d)); // Pass the 2D array and its size to the function 

    double result_3d = sum_3d(arr_3d, std::size(arr_3d), std::size(arr_3d[0])); // Pass the 3D array and its sizes to the function  

    std::cout << "The sum of the 2D array elements is: " << result_2d << std::endl;

    std::cout << "The sum of the 3D array elements is: " << result_3d << std::endl;

    return 0;

}



//Definitions
double sum_2d(const double arr[][3], size_t size){
    //When passing a multi-dimensional array to a function, the array decays into a pointer to its first element. Therefore, the function receives a pointer to the first element of the array, and the size of the array must be passed separately.

    double total{};

    for(size_t i{0}; i < size; ++i){
        for(size_t j{0}; j < 3; ++j){
            total += arr[i][j];
        }
    }

    return total;
}

double sum_3d(const double arr[][3][2], size_t size1, size_t size2){
    //When passing a multi-dimensional array to a function, the array decays into a pointer to its first element. Therefore, the function receives a pointer to the first element of the array, and the size of the array must be passed separately.

    double total{};

    for(size_t i{0}; i < size1; ++i){
        for(size_t j{0}; j < 3; ++j){
            for(size_t k{0}; k < size2; ++k){
                total += arr[i][j][k];
            }
        }
    }

    return total;
}