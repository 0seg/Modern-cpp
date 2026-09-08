/*
Your job is to write a function that checks whether the sum of all elements in an array is even. If the sum is even you would store a true in a bool input parameter called result. If the sum is odd, you would store in a false.

The function signature will be exactly as shown below

void is_sum_even(int data[], unsigned int size, bool& result)*/

#include <iostream>

//Don't modify anything above this line.
//Your code will go below this line

//Your code will go above this line
//Don't modify anything below this line

void is_sum_even(int data[], unsigned int size, bool& result){
    unsigned int s{};
    
    for(size_t i{}; i<size; ++i) s+=data[i];
    
    if(s % 2 == 0) result = true;
    else result = false;
    
}
