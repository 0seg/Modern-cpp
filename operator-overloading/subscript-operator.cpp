/* Subscript Operator for Reading */

#include <iostream>
#include <stdexcept>

class Array {
private:
    int* arr;
    size_t size;

public:
    Array(size_t size)
        : size{size}, arr{new int[size]} {}

    ~Array()
    {
        delete[] arr;
    }

    int& operator[](size_t index)
    // This operator allows for reading and writing to the array using the subscript notation.
    {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }

        return arr[index];
    }

    const int& operator[](size_t index) const
    // This operator allows for reading from the array using the subscript notation.
    {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }

        return arr[index];
    }
};

int main(){

    Array arr(5);

    for (size_t i = 0; i < 5; ++i) {
        arr[i] = static_cast<int>(i * 10);
    }

    for (size_t i = 0; i < 5; ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    try {
        std::cout << "arr[5] = " << arr[5] << std::endl; // This will throw an exception
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

}