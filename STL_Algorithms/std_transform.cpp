/* std::transform in C++ */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void print_vector(const char* label, const std::vector<int>& values) {
    std::cout << label;

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

int main() {
    const std::vector<int> numbers{1, 2, 3, 4, 5};

    // 1. Transform each element into its square.
    std::vector<int> squares;

    std::transform(numbers.begin(), numbers.end(), std::back_inserter(squares), [](int value) {return value * value;});

    print_vector("Original: ", numbers);
    print_vector("Squares: ", squares);

    // 2. Transform the elements in place.
    std::vector<int> doubled = numbers;

    std::transform(doubled.begin(), doubled.end(), doubled.begin(), [](int value) {return value * 2;});

    print_vector("Doubled: ", doubled);

    // 3. Transform two ranges into a third vector.
    const std::vector<int> other{10, 20, 30, 40, 50};
    std::vector<int> sums;

    std::transform(numbers.begin(), numbers.end(), other.begin(), std::back_inserter(sums), [](int a, int b) {return a + b;});

    print_vector("Sums: ", sums);

    return 0;
}
