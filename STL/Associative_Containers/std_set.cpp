
#include <iostream>
#include <set>

void print_set(const char* label, const std::set<int>& values) {
    std::cout << label;

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

int main() {
    // 1. Initialize a set.
    std::set<int> numbers{5, 2, 8, 2, 1, 5, 3, 6};
    print_set("Initial set: ", numbers);

    // 2. Insert an element.
    auto [it, inserted] = numbers.insert(4);

    std::cout << "Inserted 4? " << std::boolalpha
              << inserted << '\n';

    // 3. Try to insert a duplicate.
    auto [duplicate_it, duplicate_inserted] = numbers.insert(4);

    std::cout << "Inserted 4 again? "
              << duplicate_inserted << '\n';

    // 4. Search for an element.
    auto found = numbers.find(8);

    if (found != numbers.end()) {
        std::cout << "Found: " << *found << '\n';
    } else {
        std::cout << "8 not found\n";
    }

    // 5. Check whether an element exists.
    std::cout << "Contains 10? "
              << (numbers.find(10) != numbers.end()) << '\n';

    // 6. Erase an element by value.
    numbers.erase(2);
    print_set("After erasing 2: ", numbers);

    // 7. Find the first element >= 5.
    auto lower = numbers.lower_bound(5);

    if (lower != numbers.end()) {
        std::cout << "lower_bound(5): " << *lower << '\n';
    }

    // 8. Find the first element > 5.
    auto upper = numbers.upper_bound(5);

    if (upper != numbers.end()) {
        std::cout << "upper_bound(5): " << *upper << '\n';
    }

    // 9. Inspect the set.
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Empty? " << numbers.empty() << '\n';

    // 10. Clear all elements.
    numbers.clear();
    print_set("After clear: ", numbers);

    return 0;
}
