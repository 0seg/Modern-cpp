#include <algorithm>
#include <functional>
#include <iostream>
#include <ranges>
#include <vector>

int main() {
    std::vector<int> numbers{8, 3, 10, 1, 6, 4, 12};

    // 1. Sort using C++20 ranges.
    std::ranges::sort(numbers);

    std::cout << "Ascending: ";
    for (int n : numbers) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    // 2. Sort in descending order.
    std::ranges::sort(numbers, std::greater<>{});

    std::cout << "Descending: ";
    for (int n : numbers) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    // 3. Find a specific value.
    auto found = std::ranges::find(numbers, 6);

    if (found != numbers.end()) {
        std::cout << "Found: " << *found << '\n';
    }

    // 4. Find the first even number.
    auto first_even = std::ranges::find_if(numbers, [](int n) {return n % 2 == 0;});

    if (first_even != numbers.end()) {
        std::cout << "First even: " << *first_even << '\n';
    }

    // 5. Check whether all numbers are positive.
    bool all_positive = std::ranges::all_of(numbers, [](int n) {return n > 0;});

    std::cout << std::boolalpha;
    std::cout << "All positive: " << all_positive << '\n';

    // 6. Create a view: filter even numbers, then square them.
    auto even_squares = numbers | std::views::filter([](int n) {return n % 2 == 0;}) | std::views::transform([](int n) {return n * n;});

    std::cout << "Even squares: ";
    for (int n : even_squares) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    return 0;
}
