#include <iostream>

// General template: works with any type.
template <typename T>
class TypeInfo {
public:
    static void print() {
        std::cout << "General template\n";
    }
};

// Partial specialization: works with pointer types.
template <typename T>
class TypeInfo<T*> {
public:
    static void print() {
        std::cout << "Pointer specialization\n";
    }
};

// Full specialization: works specifically with bool.
template <>
class TypeInfo<bool> {
public:
    static void print() {
        std::cout << "Boolean specialization\n";
    }
};

int main() {
    TypeInfo<int>::print();
    TypeInfo<double>::print();
    TypeInfo<bool>::print();
    TypeInfo<int*>::print();
    TypeInfo<char*>::print();

    return 0;
}