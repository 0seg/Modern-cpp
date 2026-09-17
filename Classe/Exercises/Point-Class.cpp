/*
 * Point in 2D space.
 *
 * Members:
 *   - m_x : x-coordinate
 *   - m_y : y-coordinate
 *
 * distance_to() calculates the distance between
 * this point and another point using the distance formula.
 *
 * Formula:
 *   distance = sqrt((x2 - x1)^2 + (y2 - y1)^2)
 */


#include <cmath>

class Point {
public:
    double m_x{};
    double m_y{};

    // Calculate the distance to another point.
    double distance_to(const Point& other) {
        double dx = m_x - other.m_x;
        double dy = m_y - other.m_y;

        return std::sqrt(dx * dx + dy * dy);
    }
};