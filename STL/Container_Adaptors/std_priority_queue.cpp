/* std::priority_queue in C++ */
  
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    // By default, priority_queue puts the largest value at the top.
    // Example: larger number means higher priority.
    std::priority_queue<int> priorities;

    priorities.push(30);
    priorities.push(10);
    priorities.push(50);
    priorities.emplace(20);

    std::cout << "Highest priority: " << priorities.top() << '\n';
    std::cout << "\nProcessing by priority (largest first):\n";

    while (!priorities.empty()) {
        std::cout << priorities.top() << ' ';
        priorities.pop();
    }
    std::cout << '\n';

    // A min-priority queue puts the smallest value at the top.
    std::priority_queue<int, std::vector<int>, std::greater<int>> smallest_first;

    smallest_first.push(30);
    smallest_first.push(10);
    smallest_first.push(50);
    smallest_first.push(20);

    std::cout << "\nSmallest value first:\n";
    while (!smallest_first.empty()) {
        std::cout << smallest_first.top() << ' ';
        smallest_first.pop();
    }
    std::cout << '\n';

    return 0;
}

