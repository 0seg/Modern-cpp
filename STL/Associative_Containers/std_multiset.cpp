/* std::multiset in C++ */

#include <iostream>
#include <set>

void print_multiset(const char* label, const std::multiset<int>& values) {
    std::cout << label;

    if (values.empty()) {
        std::cout << "(empty)\n";
        return;
    }

    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main() {
    // 1. A multiset stores values in sorted order and allows duplicates.
    std::multiset<int> numbers{5, 2, 8, 2, 1, 5, 3};
    print_multiset("Initial multiset: ", numbers);

    // 2. Insert another occurrence of an existing value.
    numbers.insert(5);
    print_multiset("After inserting another 5: ", numbers);

    // 3. Count how many equivalent values exist.
    std::cout << "Count of 2: " << numbers.count(2) << '\n';
    std::cout << "Count of 5: " << numbers.count(5) << '\n';

    // 4. Find one occurrence of a value.
    auto found = numbers.find(2);
    if (found != numbers.end()) {
        std::cout << "Found an occurrence of: " << *found << '\n';
    }

    // 5. Erase only one occurrence using an iterator.
    found = numbers.find(2);
    if (found != numbers.end()) {
        numbers.erase(found);
    }
    print_multiset("After erasing one 2: ", numbers);

    // 6. Erase every occurrence of a value.
    numbers.erase(5);
    print_multiset("After erasing all 5s: ", numbers);

    // 7. Get the range containing all occurrences of a value.
    auto [first, last] = numbers.equal_range(2);
    std::cout << "Occurrences of 2 via equal_range: ";
    for (auto it = first; it != last; ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    // 8. Demonstrate lower_bound and upper_bound.
    auto lower = numbers.lower_bound(3); // First value >= 3.
    auto upper = numbers.upper_bound(3); // First value > 3.

    if (lower != numbers.end()) {
        std::cout << "lower_bound(3): " << *lower << '\n';
    }
    if (upper != numbers.end()) {
        std::cout << "upper_bound(3): " << *upper << '\n';
    }

    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << std::boolalpha << "Empty? " << numbers.empty() << '\n';

    numbers.clear();
    print_multiset("After clear: ", numbers);

    return 0;
}
