/* Iterators in C++ */

#include <iostream>
#include <vector>

int main(){

    std::vector<int> vector_ints{1, 2, 3, 4, 5}; // Initialize a vector with some integers

    // Display the original vector using iterators
    std::cout << "Original vector: ";
    for(auto it = vector_ints.begin(); it != vector_ints.end(); ++it){
        std::cout << *it << " "; // Dereference the iterator to access the element
    }

    std::cout << std::endl;


    std::vector<int> other_vector{7, 8, 9, 10, 11}; // Another vector to demonstrate concatenation

    // Display the other vector using iterators
    std::cout << "Other vector: ";
    for(auto it = other_vector.begin(); it != other_vector.end(); ++it){
        std::cout << *it << " "; // Dereference the iterator to access the element
    }

    std::cout << std::endl;

    std::vector<int> sum_vector; // Vector to hold the sum of elements from both vectors

    for(auto it1 = vector_ints.begin(), it2 = other_vector.begin(); it1 != vector_ints.end() && it2 != other_vector.end(); ++it1, ++it2){
        sum_vector.push_back(*it1 + *it2); // Add corresponding elements from both vectors and store in sum_vector
    }

    // Display the sum_vector
    std::cout << "Sum of corresponding elements from both vectors: ";
    for(auto it = sum_vector.begin(); it != sum_vector.end(); ++it){
        std::cout << *it << " "; // Dereference the iterator to access the element  
    }
    std::cout << std::endl;

    return 0;

}