/*max_element and min_element in C++*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

void print_values(const char* label, const std::vector<int>& values) {
    std::cout << label;

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

int main() {
    const int a = 18;
    const int b = 7;

    // 1. std::min and std::max compare two values.
    std::cout << "std::min(18, 7): " << std::min(a, b) << '\n';

    std::cout << "std::max(18, 7): " << std::max(a, b) << '\n';

    const std::vector<int> numbers{12, 4, 19, 2, 15, 7, 2};

    print_values("Numbers: ", numbers);

    // 2. Find the minimum and maximum elements.
    const auto min_it = std::min_element(
        numbers.begin(), numbers.end()
    );

    const auto max_it = std::max_element(
        numbers.begin(), numbers.end()
    );

    if (min_it != numbers.end()) {
        std::cout << "Minimum element: " << *min_it << " (index " << std::distance(numbers.begin(), min_it) << ")\n";
    }

    if (max_it != numbers.end()) {
        std::cout << "Maximum element: " << *max_it << " (index " << std::distance(numbers.begin(), max_it) << ")\n";
    }

    // 3. Find both minimum and maximum in one call.
    const auto [minmax_min, minmax_max] =
        std::minmax_element(numbers.begin(), numbers.end());

    if (minmax_min != numbers.end()) {
        std::cout << "minmax_element -> min: " << *minmax_min << ", max: " << *minmax_max << '\n';
    }

    // 4. Find the longest string using a custom comparison.
    const std::vector<std::string> words{
        "pear", "watermelon", "fig", "banana"
    };

    const auto longest = std::max_element(words.begin(), words.end(), [](const std::string& left, const std::string& right) {
            return left.size() < right.size();
        }
    );

    if (longest != words.end()) {
        std::cout << "Longest word: " << *longest << '\n';
    }

    // 5. Handle an empty range.
    const std::vector<int> empty{};

    const auto empty_min = std::min_element(empty.begin(), empty.end());

    std::cout << "Empty vector has a minimum? " << std::boolalpha << (empty_min != empty.end()) << '\n';

    return 0;
}