/* Constructors in C++ */

#include <iostream> 


const double PI {3.14159265358979323846};

class Cylinder {
    private:
        double radius{1};
        double height{1};
    
        public:
        //Constructor with parameters
        Cylinder(double r, double h) : radius(r), height(h) {} // Initializer list to initialize radius and height

        double volume() {
            return PI * radius * radius * height;
        }
    

};

int main(){

    Cylinder c1(5.0, 10.0); // Create an object of the Cylinder class with radius 5.0 and height 10.0

    std::cout << "Volume of the cylinder: " << c1.volume() << std::endl;

    return 0;
}