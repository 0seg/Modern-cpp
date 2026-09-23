#include <iostream>

class Square; // Forward declaration

class Circle {

private:

    double radius{1};

public:

    void setRadius(double r) {
        radius = r;
    }

    double getRadius() const {
        return radius;
    }

    double area() const {
        return 3.14159 * radius * radius;
    }

    // Square can access Circle's private members
    friend class Square;
};

class Square {

private:

    double side{1};

public:

    void setSide(double s) {
        side = s;
    }

    double getSide() const {
        return side;
    }

    double area() const {
        return side * side;
    }

    void displayCircleRadius(const Circle& c) {
        std::cout << "Circle radius: " << c.radius << std::endl;
    }
};

int main() {

    Circle c1;
    c1.setRadius(5.0);

    Square s1;
    s1.setSide(4.0);

    std::cout << "Circle radius: " << c1.getRadius() << std::endl;
    std::cout << "Circle area: " << c1.area() << std::endl;

    std::cout << "Square side: " << s1.getSide() << std::endl;
    std::cout << "Square area: " << s1.area() << std::endl;

    s1.displayCircleRadius(c1);

    return 0;
}