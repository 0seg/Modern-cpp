#include "exercise.h"

//Don't modify anything above this line
//Your code should be below this line


/*
    Factorial Function

    Your job is to write a factorial function with the signature:

    unsigned int factorial(unsigned int n)

    using recursion.

    Factorial:
    The factorial of a non-negative integer n is the product of all
    positive integers less than or equal to n.

    Examples:

    factorial(0) = 1
    factorial(1) = 1
    factorial(2) = 2
    factorial(3) = 6
    factorial(4) = 24
    factorial(5) = 120

    The function must use recursion.
*/

unsigned int factorial(unsigned int n) {
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}


//Your code should go above this line
//Don't modify anything below this line