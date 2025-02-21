#include "Point.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 4.0f);

    // Test points
    Point p1(2.0f, 2.0f);    // Inside the triangle
    Point p2(4.0f, 4.0f);    // Outside the triangle
    Point p3(2.0f, 0.0f);    // On the edge
    Point p4(0.0f, 0.0f);    // On vertex

    std::cout << "Point (2,2) is " << (bsp(a, b, c, p1) ? "inside" : "outside") << std::endl;
    std::cout << "Point (4,4) is " << (bsp(a, b, c, p2) ? "inside" : "outside") << std::endl;
    std::cout << "Point (2,0) is " << (bsp(a, b, c, p3) ? "inside" : "outside") << std::endl;
    std::cout << "Point (0,0) is " << (bsp(a, b, c, p4) ? "inside" : "outside") << std::endl;

    return EXIT_SUCCESS;
}
