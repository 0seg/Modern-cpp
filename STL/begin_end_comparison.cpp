
#include <array>
#include <iostream>
#include <iterator>
#include <vector>

// Generic function using std::begin and std::end.
template <typename Range>
void print_range(const Range& range) {
    auto it = std::begin(range);
    auto last = std::end(range);

    for (; it != last; ++it) {
        std::cout << *it << ' ';
    }

    std::cout << '\n';
}

int main() {
    std::vector<int> numbers{10, 20, 30, 40};

    // 1. Using member functions.
    std::cout << "Member begin(): "
              << *numbers.begin() << '\n';

    std::cout << "Member end() - 1: "
              << *(numbers.end() - 1) << '\n';

    // 2. Using std::begin and std::end.
    std::cout << "std::begin(): "
              << *std::begin(numbers) << '\n';

    std::cout << "std::end() - 1: "
              << *(std::end(numbers) - 1) << '\n';

    // 3. Iterate using member functions.
    std::cout << "\nUsing member iterators: ";

    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << ' ';
    }

    std::cout << '\n';

    // 4. Iterate using std::begin and std::end.
    std::cout << "Using std iterators: ";
    print_range(numbers);

    // 5. std::array.
    std::array<int, 3> values{1, 2, 3};

    std::cout << "std::array: ";
    print_range(values);

    // 6. Native array.
    int native_array[]{5, 6, 7};

    std::cout << "Native array: ";
    print_range(native_array);

    return 0;
}
