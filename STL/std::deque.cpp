/** std::deque in C++ */

#include <deque>
#include <iostream>

void print_deque(const char* label, const std::deque<int>& values) {
    std::cout << label;

    if (values.empty()) {
        std::cout << "(empty)\n";
        return;
    }

    for (const auto& value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

int main() {
    std::deque<int> numbers{1, 2, 3, 4, 5};

    print_deque("Initial: ", numbers);

    // Add elements at both ends.
    numbers.push_back(6);
    numbers.push_front(0);
    print_deque("After push_back and push_front: ", numbers);

    // Insert before index 3.
    numbers.insert(numbers.begin() + 3, 99);
    print_deque("After insert: ", numbers);

    // Remove elements at both ends.
    if (!numbers.empty()) {
        numbers.pop_back();
        numbers.pop_front();
    }
    print_deque("After pop_back and pop_front: ", numbers);

    // Access elements.
    std::cout << "Element at index 2: " << numbers.at(2) << '\n';
    std::cout << "Front: " << numbers.front() << '\n';
    std::cout << "Back: " << numbers.back() << '\n';
    std::cout << "Size: " << numbers.size() << '\n';

    // Erase the element at index 1.
    numbers.erase(numbers.begin() + 1);
    print_deque("After erase: ", numbers);

    // Clear all elements.
    numbers.clear();
    print_deque("After clear: ", numbers);

    std::cout << std::boolalpha;
    std::cout << "Is empty? " << numbers.empty() << '\n';

    // Construct new elements at both ends.
    numbers.emplace_back(10);
    numbers.emplace_front(-1);
    print_deque("After emplace: ", numbers);

    return 0;
}

