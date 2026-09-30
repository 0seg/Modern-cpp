#include <iostream>

class Complex
{
private:
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(float r, float i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real,
                       imag + other.imag);
    }

    void display() const
    {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main()
{
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);

    Complex c3 = c1 + c2;

    std::cout << "c1: ";
    c1.display();

    std::cout << "c2: ";
    c2.display();

    std::cout << "c3 (c1 + c2): ";
    c3.display();
}