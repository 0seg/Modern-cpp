/* Compound Operators in C++ */

#include <iostream>

class Complex
{
    private:
        float real;
        float imag;

    public:
        Complex() : real(0), imag(0) {}

        Complex(float r, float i) : real(r), imag(i) {}

        Complex& operator+=(const Complex& other)
        {
            real += other.real;
            imag += other.imag;
            return *this;
        }

        Complex& operator-=(const Complex& other)
        {
            real -= other.real;
            imag -= other.imag;
            return *this;
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

    std::cout << "Before compound operations:" << std::endl;
    std::cout << "c1: ";
    c1.display();
    std::cout << "c2: ";
    c2.display();

    c1 += c2; // Using the compound addition operator
    std::cout << "\nAfter c1 += c2:" << std::endl;
    std::cout << "c1: ";
    c1.display();

    c1 -= c2; // Using the compound subtraction operator
    std::cout << "\nAfter c1 -= c2:" << std::endl;
    std::cout << "c1: ";
    c1.display();

    return 0;
}