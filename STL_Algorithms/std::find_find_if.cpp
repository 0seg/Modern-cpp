/*std::find and std::find_if in C++*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers{11, 7, 24, 9, 18, 3};

    // 1. std::find: search for a specific value.
    auto found = std::find(numbers.begin(), numbers.end(), 18);

    if (found != numbers.end()) {
        std::cout << "Found value: " << *found << '\n'; std::cout << "Index: " << std::distance(numbers.begin(), found)<< '\n';
    } else {
        std::cout << "Value not found.\n";
    }

    // 2. std::find_if: find the first even number.
    auto first_even = std::find_if(numbers.begin(), numbers.end(),[](int value) {return value % 2 == 0;});

    if (first_even != numbers.end()) {
        std::cout << "First even number: "<< *first_even << '\n';
    } else {
        std::cout << "No even number found.\n";
    }

    // 3. std::find_if: find the first number greater than 20.
    auto greater_than_20 = std::find_if(numbers.begin(), numbers.end(), [](int value) {return value > 20;});

    if (greater_than_20 != numbers.end()) {
        std::cout << "First number greater than 20: " << *greater_than_20 << '\n';
    }

    // 4. Search for a value that does not exist.
    auto missing = std::find(numbers.begin(), numbers.end(), 100);

    std::cout << std::boolalpha << "Was 100 found? " << (missing != numbers.end()) << '\n';

    return 0;
}