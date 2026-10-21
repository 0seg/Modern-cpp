
#include <algorithm>
#include <forward_list>
#include <iostream>

void print_forward_list(
    const char* label,
    const std::forward_list<int>& values
) {
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
    std::forward_list<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    print_forward_list("Initial: ", numbers);

    // 1. Insert at the front.
    numbers.push_front(0);
    print_forward_list("After push_front: ", numbers);

    // 2. Insert after the second element.
    auto it = numbers.begin();
    ++it;
    numbers.insert_after(it, 99);

    print_forward_list("After insert_after: ", numbers);

    // 3. Remove the first element.
    numbers.pop_front();
    print_forward_list("After pop_front: ", numbers);

    // 4. Remove the element after the first element.
    it = numbers.begin();
    numbers.erase_after(it);

    print_forward_list("After erase_after: ", numbers);

    // 5. Find and erase the first occurrence of 3.
    auto target = std::find(numbers.begin(), numbers.end(), 3);

    if (target != numbers.end()) {
        auto previous = numbers.before_begin();

        for (auto current = numbers.begin();
             current != target; ++current) {
            previous = current;
        }

        numbers.erase_after(previous);
    }

    print_forward_list("After removing 3: ", numbers);

    // 6. Remove all even numbers.
    numbers.remove_if([](int value) {
        return value % 2 == 0;
    });

    print_forward_list("After removing even numbers: ", numbers);

    // 7. Sort and reverse the list.
    numbers.sort();
    print_forward_list("Sorted: ", numbers);

    numbers.reverse();
    print_forward_list("Reversed: ", numbers);

    // 8. Remove consecutive duplicates.
    std::forward_list<int> repeated{4, 2, 4, 2, 2, 7, 4};

    repeated.sort();
    repeated.unique();

    print_forward_list("Sorted unique values: ", repeated);

    // 9. Clear the list.
    numbers.clear();

    print_forward_list("After clear: ", numbers);
    std::cout << std::boolalpha
              << "Is empty? " << numbers.empty() << '\n';

    return 0;
}
