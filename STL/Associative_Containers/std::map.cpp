
#include <iostream>
#include <map>
#include <string>

void print_map(const char* label, const std::map<std::string, int>& values){
    std::cout << label;

    for (const auto& [key, value] : values) {
        std::cout << key << ": " << value << '\n';
    }
}

int main() {
    std::cout << std::boolalpha;

    // 1. Initialize a map.
    std::map<std::string, int> grades{
        {"Alice", 95},
        {"Bob", 82},
        {"Charlie", 90},
        {"Diana", 88}
    };

    print_map("Initial map:\n", grades);

    // 2. Insert or update using operator[].
    grades["Eve"] = 91;

    // 3. Insert a new key.
    bool inserted = grades.insert({"Frank", 77}).second;
    std::cout << "\nFrank inserted? " << inserted << '\n';

    // 4. Try to insert an existing key.
    inserted = grades.insert({"Bob", 100}).second;
    std::cout << "Bob inserted again? " << inserted << '\n';

    // 5. Insert only if the key does not exist.
    bool added = grades.try_emplace("Grace", 93).second;
    std::cout << "Grace added? " << added << '\n';

    // 6. Insert or update an existing key.
    grades.insert_or_assign("Bob", 85);

    print_map("\nAfter insertions and updates:\n", grades);

    // 7. Search for a key.
    auto found = grades.find("Charlie");

    if (found != grades.end()) {
        std::cout << "\nCharlie's grade: " << found->second << '\n';
    }

    // 8. Access a value with bounds checking.
    std::cout << "Alice's grade: " << grades.at("Alice") << '\n';

    // 9. Find keys relative to a given key.
    auto lower = grades.lower_bound("Charlie");
    auto upper = grades.upper_bound("Charlie");

    if (lower != grades.end()) {
        std::cout << "lower_bound: " << lower->first << '\n';
    }

    if (upper != grades.end()) {
        std::cout << "upper_bound: " << upper->first << '\n';
    }

    // 10. Erase an entry by key.
    grades.erase("Diana");
    print_map("\nAfter erasing Diana:\n", grades);

    std::cout << "Size: " << grades.size() << '\n';
    std::cout << "Empty? " << grades.empty() << '\n';

    // 11. Clear the map.
    grades.clear();
    std::cout << "Empty after clear? " << grades.empty() << '\n';

    return 0;
}
