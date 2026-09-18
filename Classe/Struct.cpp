/*
 * Struct in C++
 *
 * A struct is similar to a class, but its members are
 * public by default.
 */

#include <iostream>

struct Point {

    // Public by default
    double x{0};
    double y{0};

    // Set coordinates
    void setCoordinates(double xCoord, double yCoord) {
        x = xCoord;
        y = yCoord;
    }

    // Print coordinates
    void printCoordinates() {
        std::cout << "Point coordinates: ("
                  << x << ", " << y << ")\n";
    }
};

int main() {

    Point p1;

    p1.setCoordinates(3.0, 4.0);

    p1.printCoordinates();

    return 0;
}