/*std::list in c++*/
    
#include <functional>
#include <iostream>
#include <list>

void print_list(const char* label, const std::list<int>& values) {
    std::cout << label;

    if (values.empty()) {
        std::cout << "(empty)\n";
        return;
    }

    for (const int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

int main() {
    // 1. Initialize a doubly linked list.
    std::list<int> numbers{5, 2, 8, 2, 10};
    print_list("Initial: ", numbers);

    // 2. Insert elements at both ends.
    numbers.push_front(1);
    numbers.push_back(12);
    print_list("After push_front / push_back: ", numbers);

    // 3. Insert before a known position.
    auto position = numbers.begin();
    ++position; // Second element.
    numbers.insert(position, 99);
    print_list("After insert: ", numbers);

    // 4. Access the first and last elements.
    std::cout << "Front: " << numbers.front() << '\n';
    std::cout << "Back: " << numbers.back() << '\n';
    std::cout << "Size: " << numbers.size() << '\n';

    // 5. Find and erase the first occurrence of a value.
    auto target = numbers.begin();
    while (target != numbers.end() && *target != 8) {
        ++target;
    }

    if (target != numbers.end()) {
        numbers.erase(target);
    }
    print_list("After erasing 8: ", numbers);

    // 6. Remove every occurrence of a value.
    numbers.remove(2);
    print_list("After remove(2): ", numbers);

    // 7. Remove values that satisfy a condition.
    numbers.remove_if([](int value) {
        return value % 2 == 0;
    });
    print_list("After removing even values: ", numbers);

    // 8. Sort using the list's member function.
    numbers.sort();
    print_list("Sorted ascending: ", numbers);

    numbers.sort(std::greater<>{});
    print_list("Sorted descending: ", numbers);

    // 9. Reverse the list.
    numbers.reverse();
    print_list("After reverse: ", numbers);

    // 10. unique() removes consecutive duplicates.
    std::list<int> repeated{4, 2, 4, 2, 2, 7, 4};
    repeated.sort();
    repeated.unique();
    print_list("Sorted unique values: ", repeated);

    // 11. splice() transfers all nodes from one list into another.
    std::list<int> tasks{1, 2, 5};
    std::list<int> urgent_tasks{3, 4};
    auto insert_before = tasks.begin();
    ++insert_before; // Before 2.

    tasks.splice(insert_before, urgent_tasks);
    print_list("Tasks after splice: ", tasks);
    print_list("Urgent tasks after splice: ", urgent_tasks);

    // 12. Clear a list and check whether it is empty.
    numbers.clear();
    print_list("After clear: ", numbers);
    std::cout << std::boolalpha
              << "Is numbers empty? " << numbers.empty() << '\n';

    return 0;
}

