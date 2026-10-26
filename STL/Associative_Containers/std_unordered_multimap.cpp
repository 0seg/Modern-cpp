/* std::unordered_multimap in C++ */

#include <iostream>
#include <string>
#include <unordered_map>

using ScoreTable = std::unordered_multimap<std::string, int>;

void print_scores(const char* label, const ScoreTable& scores) {
    std::cout << label;

    if (scores.empty()) {
        std::cout << "(empty)\n";
        return;
    }

    for (const auto& [name, score] : scores) {
        std::cout << name << ": " << score << '\n';
    }
}

int main() {
    // 1. Create an unordered_multimap: keys may appear more than once.
    ScoreTable scores{
        {"Alice", 90},
        {"Bob", 82},
        {"Alice", 96},
        {"Charlie", 88},
        {"Bob", 91}
    };
    print_scores("Initial scores (order is unspecified):\n", scores);

    // 2. Insert another entry with an existing key.
    scores.emplace("Alice", 99);
    scores.emplace("Diana", 87);
    print_scores("\nAfter emplace():\n", scores);

    // 3. Find one entry for a key.
    auto found = scores.find("Bob");
    if (found != scores.end()) {
        std::cout << "One Bob score: " << found->second << '\n';
    } else {
        std::cout << "Bob not found\n";
    }

    // 4. Get every entry for the same key.
    auto [first, last] = scores.equal_range("Alice");
    std::cout << "All Alice scores: ";
    for (auto it = first; it != last; ++it) {
        std::cout << it->second << ' ';
    }
    std::cout << '\n';

    // 5. Remove one specific entry (Alice, 96), not every Alice entry.
    auto range = scores.equal_range("Alice");
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second == 96) {
            scores.erase(it);
            break;
        }
    }
    print_scores("\nAfter removing Alice's score of 96:\n", scores);

    // 6. Erase all entries associated with a key.
    const auto removed = scores.erase("Bob");
    std::cout << "Removed Bob entries: " << removed << '\n';
    print_scores("After erasing Bob:\n", scores);

    // 7. Inspect hash-table information.
    std::cout << "Size: " << scores.size() << '\n';
    std::cout << "Bucket count: " << scores.bucket_count() << '\n';
    std::cout << "Load factor: " << scores.load_factor() << '\n';

    // 8. Clear all entries.
    scores.clear();
    print_scores("After clear:\n", scores);
    std::cout << std::boolalpha << "Is empty? " << scores.empty() << '\n';

    return 0;
}
