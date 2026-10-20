
#include <algorithm>
#include <iostream>
#include <vector>

// Custom functor: sorts numbers in descending order.
class Descending {
public:
    bool operator()(int a, int b) const {
        return a > b;
    }
};

int main() {
    std::vector<int> numbers{8, 3, 10, 1, 6, 4, 12};

    // 1. Sort using our custom functor.
    std::sort(numbers.begin(), numbers.end(), Descending{});

    std::cout << "Descending: ";
    for (int n : numbers) {
        std::cout << n << ' ';
    }

    // 2. Sort using a standard functor.
    std::sort(numbers.begin(), numbers.end(), std::less<>{});

    std::cout << "\nAscending: ";
    for (int n : numbers) {
        std::cout << n << ' ';
    }

    return 0;
}
