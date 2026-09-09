/**
 * Inline Functions in C++
 *
 * An inline function is a function declared with the `inline` keyword.
 *
 * `inline` allows the function to be defined in multiple translation units
 * without violating the One Definition Rule (ODR), as long as the
 * definitions are equivalent.
 *
 * Historically, `inline` was also used as a request to the compiler to
 * replace a function call with the function's body:
 *
 *     add(x, y)
 *
 * could conceptually become:
 *
 *     x + y
 *
 * This can avoid the overhead of a function call.
 *
 * IMPORTANT:
 * `inline` does NOT guarantee that the compiler will perform this
 * optimization. The compiler decides whether inlining is beneficial.
 *
 * Modern compilers are very good at deciding when to inline functions,
 * especially when optimization is enabled.
 *
 * Example:
 */

#include <iostream>

inline int add(int a, int b) {
    return a + b;
}

int main() {

    int x{5};
    int y{10};

    int result = add(x, y);

    std::cout << "Sum of x and y: "
              << result << '\n';

    return 0;
}