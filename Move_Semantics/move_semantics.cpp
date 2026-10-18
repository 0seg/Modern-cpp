#include <cstddef>
#include <iostream>
#include <utility>

class Buffer {
private:
    int* data_{};
    std::size_t size_{};

public:
    explicit Buffer(std::size_t size)
        : data_(size ? new int[size]{} : nullptr),
          size_(size) {}

    // Copy constructor: create an independent copy.
    Buffer(const Buffer& other)
        : data_(other.size_ ? new int[other.size_] : nullptr),
          size_(other.size_) {
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
        std::cout << "Copy constructor\n";
    }

    // Move constructor: transfer ownership.
    Buffer(Buffer&& other) noexcept
        : data_(other.data_),
          size_(other.size_) {
        other.data_ = nullptr;
        other.size_ = 0;

        std::cout << "Move constructor\n";
    }

    // Copy assignment: replace contents with a copy.
    Buffer& operator=(const Buffer& other) {
        if (this == &other) {
            return *this;
        }

        int* new_data =
            other.size_ ? new int[other.size_] : nullptr;

        for (std::size_t i = 0; i < other.size_; ++i) {
            new_data[i] = other.data_[i];
        }

        delete[] data_;
        data_ = new_data;
        size_ = other.size_;

        std::cout << "Copy assignment\n";
        return *this;
    }

    // Move assignment: release old resources and take ownership.
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data_;

            data_ = other.data_;
            size_ = other.size_;

            other.data_ = nullptr;
            other.size_ = 0;
        }

        std::cout << "Move assignment\n";
        return *this;
    }

    ~Buffer() {
        delete[] data_;
    }

    std::size_t size() const {
        return size_;
    }

    void set(std::size_t index, int value) {
        if (index < size_) {
            data_[index] = value;
        }
    }

    void print() const {
        for (std::size_t i = 0; i < size_; ++i) {
            std::cout << data_[i] << ' ';
        }
        std::cout << '\n';
    }
};

int main() {
    Buffer a(3);
    a.set(0, 10);
    a.set(1, 20);
    a.set(2, 30);

    Buffer b(a);             // Copy constructor
    Buffer c(std::move(a));  // Move constructor

    Buffer d(1);
    d = b;                   // Copy assignment
    d = std::move(c);        // Move assignment

    std::cout << "d: ";
    d.print();

    std::cout << "c size: " << c.size() << '\n';
    std::cout << "a size: " << a.size() << '\n';
}