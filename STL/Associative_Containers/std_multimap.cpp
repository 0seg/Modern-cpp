/* std::multimap in C++ */

#include <iostream>
#include <map>
#include <string>
#include <utility>

void print_multimap(const char* label, const std::multimap<std::string, int>& values){
    std::cout << label;

    if (values.empty()) {
        std::cout << "(empty)\n";
        return;
    }

    for (const auto& [key, value] : values) {
        std::cout << key << ": " << value << '\n';
    }
}

int main() {
    // 1. A multimap stores key-value pairs and allows equivalent keys.
    std::multimap<std::string, int> scores{
        {"Alice", 90},
        {"Bob", 82},
        {"Alice", 96},
        {"Charlie", 88},
        {"Bob", 91}
    };
    print_multimap("Initial multimap:\n", scores);

    // 2. Add another value for an existing key.
    scores.emplace("Alice", 99);
    print_multimap("\nAfter adding another Alice score:\n", scores);

    // 3. Find one entry for a key.
    auto found = scores.find("Bob");
    if (found != scores.end()) {
        std::cout << "One Bob entry: " << found->second << '\n';
    }

    // 4. Read all entries associated with a key.
    auto [first, last] = scores.equal_range("Alice");
    std::cout << "Alice's scores: ";
    for (auto it = first; it != last; ++it) {
        std::cout << it->second << ' ';
    }
    std::cout << '\n';

    // 5. Count the entries for a key.
    std::cout << "Number of Alice entries: " << scores.count("Alice") << '\n';

    // 6. Erase the first entry in the equivalent-key range.
    auto first_bob = scores.lower_bound("Bob");
    if (first_bob != scores.end() && first_bob->first == "Bob") {
        scores.erase(first_bob);
    }
    print_multimap("\nAfter erasing one Bob entry:\n", scores);

    // 7. Erase all entries associated with a key.
    scores.erase("Alice");
    print_multimap("\nAfter erasing all Alice entries:\n", scores);

    // 8. Inspect the sorted key range.
    auto lower = scores.lower_bound("Bob");
    auto upper = scores.upper_bound("Bob");
    std::cout << "Entries in the Bob key range:\n";
    for (auto it = lower; it != upper; ++it) {
        std::cout << it->first << ": " << it->second << '\n';
    }

    std::cout << "Size: " << scores.size() << '\n';
    std::cout << std::boolalpha << "Empty? " << scores.empty() << '\n';

    scores.clear();
    print_multimap("After clear:\n", scores);

    return 0;
}
