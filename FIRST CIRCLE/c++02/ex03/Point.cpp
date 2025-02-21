#include "Point.hpp"

Point::Point() : x(0), y(0)
{
    std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
    std::cout << "Point parameterized constructor called with x=" << x << ", y=" << y << std::endl;
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
    std::cout << "Point copy constructor called with x=" << other.x << ", y=" << other.y << std::endl;
}

Point& Point::operator=(const Point& other)
{
    // Since x and y are const, we can't modify them
    // This is just to satisfy the Orthodox Canonical Form
    //
    std::cout << "Point assignation operator called with x=" << other.x << ", y=" << other.y << std::endl;
    (void)other;
    return *this;
}

Point::~Point()
{
    std::cout << "Point destructor called" << std::endl;
}

Fixed Point::getX() const
{
    std::cout << "getX() called" << std::endl;
    return this->x;
}

Fixed Point::getY() const
{
    std::cout << "getY() called" << std::endl;
    return this->y;
}
