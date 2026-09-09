// Odd Series
//
// The odd() function returns odd numbers starting from 1.
// Each time it is called, it returns the next odd number.
//
// Example:
// odd(); // returns 1
// odd(); // returns 3
// odd(); // returns 5
//
// The print_odds() function uses odd() to print a given number
// of odd numbers.
//
// Example:
// print_odds(5);
//
// Output:
// 1 3 5 7 9 
//
// print_odds(10);
//
// Output:
// 1 3 5 7 9 11 13 15 17 19 
//
// There must be a single space after the last odd number.
//
// Hint:
// Use a static variable to keep the state of odd() between calls.

int odd() {
    static int n = 1;
    int result = n;
    n += 2;
    return result;
}

void print_odds(unsigned int count) {
    for (unsigned int i = 0; i < count; i++) {
        std::cout << odd() << " ";
    }
}