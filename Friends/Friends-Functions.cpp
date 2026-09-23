/*friends functions in C++*/


#include <iostream>

class Circle {

private:

    double radius{1};

public:

    // Setter for radius
    void setRadius(double r) {
        radius = r;
    }

    // Getter for radius
    double getRadius() const {
        return radius;
    }

    // Calculate area
    double area() const {
        return 3.14159 * radius * radius;
    }

    // Friend function declaration
    friend void displayCircleInfo(const Circle& c);
};

// Friend function definition
void displayCircleInfo(const Circle& c) {

    std::cout << "Radius of the circle: "
              << c.radius << std::endl;

    std::cout << "Area of the circle: "
              << c.area() << std::endl;
}

int main() {

    Circle c1;

    c1.setRadius(5.0);

    displayCircleInfo(c1);

    return 0;
}