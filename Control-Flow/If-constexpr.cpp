#include <iostream>

// This example demonstrates the use of if constexpr.

int main() {

    // constexpr means that the value of condition is known at compile time.
    constexpr bool condition = true;

    // if constexpr evaluates the condition at compile time.
    // Since condition is true, only this branch is selected.
    if constexpr (condition) {

        std::cout << "Condition is true." << std::endl;

    } else {

        // This branch is discarded at compile time because condition is true.
        std::cout << "Condition is false." << std::endl;

    }


    // if constexpr evaluates a condition at compile time.
    // Unlike a regular if statement, the branch whose condition is false
    // can be discarded during compilation.

    return 0;
}

