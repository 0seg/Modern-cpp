/* std::all_of, std::any_of, and std::none_of in C++ */

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    const std::vector<int> numbers{2, 4, 6, 8, 10};
    const std::vector<int> mixed{2, 3, 6, 8, 10};

    // 1. all_of: Are ALL elements even?
    const bool all_even = std::all_of(
        numbers.begin(), numbers.end(),
        [](int value) {
            return value % 2 == 0;
        }
    );

    // 2. any_of: Is AT LEAST ONE element odd?
    const bool any_odd = std::any_of(
        mixed.begin(), mixed.end(),
        [](int value) {
            return value % 2 != 0;
        }
    );

    // 3. none_of: Are NONE of the elements negative?
    const bool none_negative = std::none_of(
        numbers.begin(), numbers.end(),
        [](int value) {
            return value < 0;
        }
    );

    std::cout << std::boolalpha;
    std::cout << "All numbers are even: " << all_even << '\n';
    std::cout << "At least one number is odd: " << any_odd << '\n';
    std::cout << "No numbers are negative: " << none_negative << '\n';

    // Bonus: none_of returns true for an empty range.
    const std::vector<int> empty{};
    const bool empty_has_no_negatives = std::none_of(
        empty.begin(), empty.end(),
        [](int value) {
            return value < 0;
        }
    );

    std::cout << "Empty range has no negative elements: "
              << empty_has_no_negatives << '\n';

    return 0;
}
