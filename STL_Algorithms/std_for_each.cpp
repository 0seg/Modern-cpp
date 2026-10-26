/* std::for_each in C++ */
  
#include <algorithm>
#include <iostream>
#include <vector>

void print_numbers(const char* label, const std::vector<int>& numbers) {
    std::cout << label;
    for (int number : numbers) {
        std::cout << number << ' ';
    }
    std::cout << '\n';
}

struct PrintSquare {
    void operator()(int value) const {
        std::cout << value * value << ' ';
    }
};

int main() {
    std::vector<int> numbers{1, 2, 3, 4, 5};

    // 1. Visit every element and print it.
    std::cout << "Original numbers: ";
    std::for_each(numbers.begin(), numbers.end(), [](int value) {
        std::cout << value << ' ';
    });
    std::cout << '\n';

    // 2. Modify the original elements by reference.
    std::for_each(numbers.begin(), numbers.end(), [](int& value) {
        value *= 2;
    });
    print_numbers("Doubled numbers: ", numbers);

    // 3. Accumulate a sum using a reference capture.
    int total = 0;
    std::for_each(numbers.begin(), numbers.end(), [&total](int value) {
        total += value;
    });
    std::cout << "Sum: " << total << '\n';

    // 4. Use a custom functor.
    std::cout << "Squares: ";
    std::for_each(numbers.begin(), numbers.end(), PrintSquare{});
    std::cout << '\n';

    return 0;
}
