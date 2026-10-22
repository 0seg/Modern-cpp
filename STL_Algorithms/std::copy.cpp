#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void print_vector(const char* label, const std::vector<int>& values) {
    std::cout << label;

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

int main() {
    const std::vector<int> numbers{10, 20, 30, 40, 50};

    // 1. Copy all elements into an empty vector.
    std::vector<int> copied;

    std::copy(numbers.begin(), numbers.end(), std::back_inserter(copied));

    print_vector("Original: ", numbers);
    print_vector("Copied: ", copied);

    // 2. Copy a subrange: indices [1, 4).
    std::vector<int> partial;

    std::copy(numbers.begin() + 1, numbers.begin() + 4, std::back_inserter(partial) );

    print_vector("Partial copy: ", partial);

    // 3. Copy into an existing, correctly sized vector.
    std::vector<int> destination(numbers.size());

    std::copy(numbers.begin(), numbers.end(), destination.begin());

    print_vector("Destination: ", destination);

    // 4. Copy elements that satisfy a condition.
    std::vector<int> even_numbers;

    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(even_numbers), [](int value) {return value % 20 == 0;});

    print_vector("Multiples of 20: ", even_numbers);

    return 0;
}