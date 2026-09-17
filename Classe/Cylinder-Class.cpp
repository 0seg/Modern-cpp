/* class Cylinder in c++ */

#include <iostream>

const double PI {3.14159265358979323846};

class Cylinder {
    // Private member variables for radius and height
    private:
        double radius{3.0};
        double height{5.0};
    // Public member function to calculate the volume of the cylinder
    public:
        double volume() {
            return PI * radius * radius * height;
        }
    
};


int main() {
    Cylinder c1; // Create an object of the Cylinder class


    std::cout << "Volume of the cylinder: " << c1.volume() << std::endl;

    return 0;
}