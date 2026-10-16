/*class templates*/

#include <iostream>
#include <string>
#include <cstddef>

template <typename T>
class MiniVector {

    std::size_t size{};
    std::size_t capacity{};
    T* data{};

public:
    MiniVector() = default;
    MiniVector(std::size_t initial_size)
        : size{initial_size},
        capacity{initial_size},
        data{new T[initial_size]{}} {}

    ~MiniVector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size >= capacity) {
            T value_copy = value; 
            resize();
            data[size] = value_copy; 
        }
        else {
            data[size] = value;
        }
        size++;
    }
    void resize() {
        const size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
        T* newData = new T[new_capacity]{};
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = new_capacity;
    }

    size_t getSize() const {
        return size;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const MiniVector<T>& vec) {
        os << "[";
        for (size_t i = 0; i < vec.size; ++i) {
            os << vec.data[i];
            if (i < vec.size - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    
};

int main() {
    MiniVector<int> intVec;
    intVec.push_back(1);
    intVec.push_back(2);
    intVec.push_back(3);

    std::cout << "Integer Vector: " << intVec << std::endl;

    MiniVector<std::string> stringVec;
    stringVec.push_back("Hello");
    stringVec.push_back("World");

    std::cout << "String Vector: " << stringVec << std::endl;

    return 0;
}