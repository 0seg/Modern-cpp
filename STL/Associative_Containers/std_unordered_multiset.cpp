/* std::unordered_multiset in C++ */

#include <iostream>
#include <string>
#include <unordered_set>

void print_multiset(const char* label, const std::unordered_multiset<int>& values) {
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
    // 1. Create an unordered_multiset: duplicates are allowed.
    std::unordered_multiset<int> numbers{5, 2, 8, 2, 1, 5, 3};
    print_multiset("Initial values (order is unspecified): ", numbers);

    // 2. Insert another value, including a duplicate.
    numbers.insert(5);
    numbers.insert(7);
    print_multiset("After insertions: ", numbers);

    // 3. Count how many equivalent values exist.
    std::cout << "Occurrences of 2: " << numbers.count(2) << '\n';
    std::cout << "Occurrences of 5: " << numbers.count(5) << '\n';

    // 4. Search for one occurrence.
    auto found = numbers.find(8);
    if (found != numbers.end()) {
        std::cout << "Found: " << *found << '\n';
    } else {
        std::cout << "8 not found\n";
    }

    // 5. Iterate over every occurrence of a value with equal_range().
    auto [first, last] = numbers.equal_range(5);
    std::cout << "All occurrences of 5: ";
    for (auto it = first; it != last; ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    // 6. Erase only one occurrence by iterator.
    auto one_five = numbers.find(5);
    if (one_five != numbers.end()) {
        numbers.erase(one_five);
    }
    print_multiset("After erasing one occurrence of 5: ", numbers);

    // 7. Erase all occurrences of a value.
    const auto removed = numbers.erase(2);
    std::cout << "Removed occurrences of 2: " << removed << '\n';
    print_multiset("After erasing all 2s: ", numbers);

    // 8. Inspect hash-table information.
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Bucket count: " << numbers.bucket_count() << '\n';
    std::cout << "Load factor: " << numbers.load_factor() << '\n';

    // reserve() can reduce rehashing when the expected size is known.
    numbers.reserve(100);
    std::cout << "Bucket count after reserve(100): "
              << numbers.bucket_count() << '\n';

    // 9. Clear all elements.
    numbers.clear();
    print_multiset("After clear: ", numbers);
    std::cout << std::boolalpha << "Is empty? " << numbers.empty() << '\n';

    return 0;
}
