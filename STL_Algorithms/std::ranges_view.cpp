#include <iostream>
#include <map>
#include <ranges>
#include <string>
#include <vector>

// Print any range whose elements can be written to std::cout.
template <std::ranges::input_range Range>
void print_range(const char* label, Range&& range) {
    std::cout << label;

    for (auto&& value : range) {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

int main() {
    const std::vector<int> numbers{
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };

    print_range("Original: ", numbers);

    // 1. Filter even numbers.
    auto even = numbers
        | std::views::filter([](int n) {
              return n % 2 == 0;
          });

    print_range("Even numbers: ", even);

    // 2. Transform elements into their squares.
    auto squares = numbers
        | std::views::transform([](int n) {
              return n * n;
          });

    print_range("Squares: ", squares);

    // 3. Filter, transform, and take the first three results.
    auto even_squares = numbers
        | std::views::filter([](int n) {
              return n % 2 == 0;
          })
        | std::views::transform([](int n) {
              return n * n;
          })
        | std::views::take(3);

    print_range("First three even squares: ", even_squares);

    // 4. Skip the first three elements.
    auto skipped = numbers | std::views::drop(3);

    print_range("Drop first three: ", skipped);

    // 5. Take elements while the condition is true.
    auto small = numbers
        | std::views::take_while([](int n) {
              return n < 5;
          });

    print_range("Take while n < 5: ", small);

    // 6. Skip the initial elements while the condition is true.
    auto remaining = numbers
        | std::views::drop_while([](int n) {
              return n < 5;
          });

    print_range("Drop while n < 5: ", remaining);

    // 7. Traverse the range in reverse.
    auto reversed = numbers | std::views::reverse;

    print_range("Reversed: ", reversed);

    // 8. Generate a sequence of integers.
    auto generated = std::views::iota(1, 6);

    print_range("Generated with iota: ", generated);

    // 9. Flatten a range of ranges.
    std::vector<std::vector<int>> groups{
        {1, 2},
        {3, 4},
        {5, 6}
    };

    auto flattened = groups | std::views::join;

    print_range("Joined groups: ", flattened);

    // 10. Access keys and values from a map.
    const std::map<std::string, int> grades{
        {"Ana", 95},
        {"Luis", 88},
        {"Mia", 78}
    };

    print_range("Names: ", grades | std::views::keys);
    print_range("Grades: ", grades | std::views::values);

    return 0;
}