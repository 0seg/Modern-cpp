
#include <array>
#include <cstddef>
#include <iostream>

template <typename T, std::size_t N>
void print_array(const std::array<T, N>& arr) {
    for (const auto& element : arr) {
        std::cout << element << ' ';
    }

    std::cout << '\n';
}

int main() {
    // 1. Initialize an array with values.
    std::array<int, 5> numbers{1, 2, 3, 4, 5};

    std::cout << "Original array: ";
    print_array(numbers);

    // 2. Modify an element.
    numbers[2] = 10;

    std::cout << "Modified array: ";
    print_array(numbers);

    // 3. Initialize all elements to zero.
    std::array<int, 5> zeros{};

    std::cout << "Zero-initialized array: ";
    print_array(zeros);

    // 4. Assign values using an index.
    for (std::size_t i = 0; i < zeros.size(); ++i) {
        zeros[i] = static_cast<int>(i + 1);
    }

    std::cout << "Modified zeros: ";
    print_array(zeros);

    // Accessing elements 

    std::cout << "Accessing elements: ";
    std::cout << "First Element: " << numbers[0] << '\n';
    std::cout << "Using at(): " << numbers.at(1) << '\n';
    std::cout << "First Element using front(): " << numbers.front() << ", Last Element using back(): " << numbers.back() << '\n';


    
    return 0;
}
