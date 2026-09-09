/*
  Recursive Functions in C++
 */


#include <iostream>


int sum(int n){
    if(n <= 0) return 0; // Base case: if n is less than or equal to 0, return 0
    return n + sum(n - 1); // Recursive case: return n plus the sum of numbers from n-1
}


int main(){

    int number{5}; // Example number to calculate the sum of numbers from 1 to 5
    int result = sum(number); // Call the recursive function to calculate the sum

    std::cout << "Sum of numbers from 1 to " << number << " is: " << result << std::endl; // Output the result

    return 0;


}