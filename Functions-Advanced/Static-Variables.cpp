/** Static Variables in C++ */

#include <iostream>

unsigned int add_student(){
    static unsigned int student_count{0}; // The scope of this var is in add_student
    // but it's life time goes beyond the function execution.


    student_count++; // Increment the student count

    return student_count; // Return the current student count
}

int main(){

    std::cout << "Adding students..." << std::endl;

    // Adding 5 students and displaying the student count
    for(int i{0}; i<5; ++i){
        unsigned int current_count = add_student(); // Call the function to add a student
        std::cout << "Current student count: " << current_count << std::endl; // Output the current student count
    }

    return 0;
    
}