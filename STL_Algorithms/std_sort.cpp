/* std::sort in C++ */

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

void print_vector(const char* label, const std::vector<int>& values) {
    std::cout << label;

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

int main() {
    std::vector<int> numbers{8, 3, 10, 1, 6, 4, 12};

    print_vector("Original: ", numbers);

    // 1. Sort in ascending order.
    std::sort(numbers.begin(), numbers.end());

    print_vector("Ascending: ", numbers);

    // 2. Sort in descending order.
    std::sort(numbers.begin(), numbers.end(), std::greater<int>{});

    print_vector("Descending: ", numbers);

    // 3. Custom comparator: sort by distance from 6.
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {int distance_a = std::abs(a - 6); int distance_b = std::abs(b - 6); return distance_a < distance_b;});

    print_vector("Closest to 6 first: ", numbers);

    return 0;
}
