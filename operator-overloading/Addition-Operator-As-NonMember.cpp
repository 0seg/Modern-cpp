/* Addition Operator as a Non-Member Function */

#include <iostream>

class Complex
{
    friend Complex operator+(const Complex& c1, const Complex& c2);
    
    private:
        float real;
        float imag;

    public:
        Complex() : real(0), imag(0) {}   
    
        Complex(float r, float i) : real(r), imag(i) {}


        void display() const
        {
            std::cout << real << " + " << imag << "i" << std::endl;
        }
};

Complex operator+(const Complex& c1, const Complex& c2){
        return Complex(c1.real + c2.real, c1.imag + c2.imag);
    }

int main()
{

 
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);

    Complex c3{c1 + c2};

    std::cout << "c1: ";
    c1.display();

    std::cout << "c2: ";
    c2.display();

    std::cout << "c3 (c1 + c2): ";
    c3.display();
}