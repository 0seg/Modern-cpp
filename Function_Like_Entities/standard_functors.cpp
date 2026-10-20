#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers{8, 3, 10, 1, 6};

    // 1. Sort in descending order using std::greater.
    std::sort(numbers.begin(), numbers.end(), std::greater<>{});

    std::cout << "Descending: ";
    for (int n : numbers) {
        std::cout << n << ' ';
    }

    // 2. Add element by element using std::plus.
    std::vector<int> a{1, 2, 3, 4};
    std::vector<int> b{10, 20, 30, 40};
    std::vector<int> result(a.size());

    std::transform(
        a.begin(), a.end(),
        b.begin(),
        result.begin(),
        std::plus<>{}
    );

    std::cout << "\nAddition: ";
    for (int n : result) {
        std::cout << n << ' ';
    }

    // 3. Multiply element by element using std::multiplies.
    std::transform(
        a.begin(), a.end(),
        b.begin(),
        result.begin(),
        std::multiplies<>{}
    );

    std::cout << "\nMultiplication: ";
    for (int n : result) {
        std::cout << n << ' ';
    }

    // 4. Check if 10 is greater than 5 using std::greater.
    std::cout << "\n10 > 5: "
              << std::boolalpha
              << std::greater<>{}(10, 5)
              << '\n';

    return 0;
}