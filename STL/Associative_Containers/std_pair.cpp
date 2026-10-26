/* std::pair in C++ */

#include <iostream>
#include <string>
#include <utility>
#include <vector>

void print_pair(const char* label, const std::pair<int, std::string>& p) {
    std::cout << label << '(' << p.first << ", " << p.second << ")\n";
}

int main() {
    // 1. Create a pair directly.
    std::pair<int, std::string> p1{1, "one"};
    print_pair("p1: ", p1);

    // 2. Create a pair using make_pair.
    auto p2 = std::make_pair(2, std::string{"two"});
    print_pair("p2: ", p2);

    // 3. Unpack the pair using structured bindings.
    const auto& [num, str] = p2;

    std::cout << "Unpacked p2: ("
              << num << ", " << str << ")\n";

    // 4. Store pairs inside a vector.
    std::vector<std::pair<int, std::string>> pairs{
        {3, "three"},
        {4, "four"},
        {5, "five"}
    };

    std::cout << "\nVector of pairs:\n";

    for (const auto& p : pairs) {
        print_pair("  ", p);
    }

    // 5. Modify the second element of a pair.
    pairs[1].second = "FOUR";

    std::cout << "\nAfter modification:\n";

    for (const auto& p : pairs) {
        print_pair("  ", p);
    }

    // 6. Compare pairs.
    std::pair<int, std::string> p3{1, "one"};

    std::cout << "\np1 == p3: "
              << std::boolalpha
              << (p1 == p3) << '\n';

    std::cout << "p1 == p2: "
              << (p1 == p2) << '\n';

    // 7. Lexicographical comparison.
    std::pair<int, std::string> a{1, "apple"};
    std::pair<int, std::string> b{2, "banana"};

    std::cout << "a < b: " << (a < b) << '\n';

    return 0;
}
