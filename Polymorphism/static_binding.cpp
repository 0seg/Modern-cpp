/* Static Binding in C++ */


#include <iostream>

class Base {
public:
    void display() const {
        std::cout << "Base::display()\n";
    }
};

class Derived : public Base {
public:
    void display() const {
        std::cout << "Derived::display()\n";
    }
};

int main() {
    Base base;
    Derived derived;

    Base& ref = derived;

    base.display();
    derived.display();
    ref.display();
}
