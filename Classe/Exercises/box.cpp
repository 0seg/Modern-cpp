/*
 * ============================================================
 *                          BOX CLASS
 * ============================================================
 *
 * Create a Box class representing a rectangular box.
 *
 * MEMBER VARIABLES:
 *   - m_width  : Width of the box.
 *   - m_length : Length of the box.
 *   - m_height : Height of the box.
 *
 * All three variables:
 *   - Must be of type double.
 *   - Must be accessible from outside the class.
 *   - Must have a default value of 1.
 *
 * METHODS:
 *   - base_area()
 *       Returns the area of the base:
 *
 *           base_area = width * length
 *
 *   - volume()
 *       Returns the volume of the box:
 *
 *           volume = width * length * height
 *
 * Both methods must return a double.
 *
 * Example:
 *
 *   Box box;
 *   box.m_width  = 10;
 *   box.m_length = 20;
 *   box.m_height = 30;
 *
 *   std::cout << "base area : " << box.base_area() << std::endl;
 *   std::cout << "volume : " << box.volume() << std::endl;
 *
 * Expected output:
 *
 *   base area : 200
 *   volume : 6000
 *
 * ============================================================
 */



#ifndef EXERCISE_H
#define EXERCISE_H

//YOUR CODE WILL GO BELOW THIS LINE
//DON'T MODIFY ANYTHING ABOVE THIS LINE.

class Box{
    public:
        double m_width{1};
        double m_length{1};
        double m_height{1};
        
        double base_area(){
            return m_width * m_length;          
        }
        
        double volume(){
            return m_width * m_length * m_height;
        }
};

//YOUR CODE WILL GO ABOVE THIS LINE
//DON'T MODIFY ANYTHING BELOW THIS LINE

#endif // _EXERCISE_H
