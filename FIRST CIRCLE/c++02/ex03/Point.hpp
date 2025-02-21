#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;

    public:
        Point();                                    // Default constructor
        Point(const float x, const float y);        // Float constructor
        Point(const Point& other);                  // Copy constructor
        Point& operator=(const Point& other);       // Copy assignment operator
        ~Point();                                   // Destructor

        // Getter methods
        Fixed getX() const;
        Fixed getY() const;
};

// Function declaration for BSP
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
