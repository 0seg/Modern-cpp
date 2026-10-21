/* Reverse Iterators in C++ */

#include <iostream>
#include <vector>


int main (){

    std::vector<int> vector_ints{1, 2, 3, 4, 5}; // Initialize a vector with some integers

    // Display the original vector using reverse iterators
    std::cout << "Original vector in reverse order: ";
    for(auto rit = vector_ints.rbegin(); rit != vector_ints.rend(); ++rit){
        std::cout << *rit << " "; // Dereference the reverse iterator to access the element
    }

    std::cout << std::endl;
    
    return 0;

}