/* A simple example of using std::vector in C++ */

#include <iostream>
#include <vector>

int main(){

    std::vector<int> numbers{1, 2, 3, 4, 5}; // Initialize a vector with some integers

    // Display the original vector
    std::cout << "Original vector: ";
    for(size_t i = 0; i < numbers.size(); ++i){
        std::cout << numbers[i] << " "; // Access elements using the subscript operator
    }

    std::cout << std::endl;


    // Modify the vector by adding a new element
    numbers.push_back(6); 

    std::vector<int> more_numbers{7, 8, 9, 10}; // Another vector to demonstrate concatenation
 
    //Add elements from more_numbers to numbers
    numbers.insert(numbers.end(), more_numbers.begin(), more_numbers.end()); // Concatenate more_numbers to numbers

    // Display the modified vector
    std::cout << "Modified vector: ";
    for(size_t i = 0; i < numbers.size(); ++i){
        std::cout << numbers[i] << " "; // Access elements using the subscript operator 
    }

    std::cout << std::endl;

    // Remove the last element from the vector
    numbers.pop_back(); // Remove the last element

    // Display the vector after removing the last element
    std::cout << "After pop_back: ";
    for(size_t i = 0; i < numbers.size(); ++i){
        std::cout << numbers[i] << " "; // Access elements using the subscript operator
    }
    std::cout << std::endl;

    // Clear the vector
    numbers.clear(); // Remove all elements from the vector 

    std::cout << "After clear, size: " << numbers.size() << std::endl; // Display the size of the vector after clearing


    return 0; 

}
