/* Setters and Getters in C++ */

#include <iostream>

class Cylinder {
    private:
        double radius{1};
        double height{1};

    public:
        // Setter for radius
        void setRadius(double r) {
            radius = r;
        }

        // Getter for radius
        double getRadius() {
            return radius;
        }

        // Setter for height
        void setHeight(double h) {
            height = h;
        }

        // Getter for height
        double getHeight() {
            return height;
        }
};



int main(){

    Cylinder c1; // Create an object of the Cylinder class

    c1.setRadius(5.0); // Set the radius using the setter
    c1.setHeight(10.0); // Set the height using the setter

    std::cout << "Radius of the cylinder: " << c1.getRadius() << std::endl; // Get the radius using the getter
    std::cout << "Height of the cylinder: " << c1.getHeight() << std::endl; // Get the height using the getter  




    return 0;
}