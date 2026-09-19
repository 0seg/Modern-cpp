/*
 * Const Member Functions in C++
 *
 * A const member function is a function that cannot modify the object's state.
 */


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
        double getRadius() const { // Marked as const
            return radius;
        }

        double area() const { // Marked as const
            return 3.14159 * radius * radius;
        }
};



int main(){

    Circle c1; // Create an object of the Circle class

    c1.setRadius(5.0); // Set the radius using the setter

    std::cout << "Radius of the circle: " << c1.getRadius() << std::endl; // Get the radius using the getter
    std::cout << "Area of the circle: " << c1.area() << std::endl; // Get the area using the method

    return 0;

}