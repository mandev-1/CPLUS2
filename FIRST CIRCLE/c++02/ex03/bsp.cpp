#include "Point.hpp"

// Helper function to calculate area of triangle
static Fixed area(Point const a, Point const b, Point const c)
{
    return Fixed(0.5f) * (
        (a.getX() * (b.getY() - c.getY()) +
         b.getX() * (c.getY() - a.getY()) +
         c.getX() * (a.getY() - b.getY()))
    );
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed totalArea;
    Fixed area1;
    Fixed area2;
    Fixed area3;

    totalArea = area(a, b, c);
    area1 = area(point, b, c);
    area2 = area(a, point, c);
    area3 = area(a, b, point);

    if (totalArea < 0)
        totalArea = totalArea * Fixed(-1);
    if (area1 < 0)
        area1 = area1 * Fixed(-1);
    if (area2 < 0)
        area2 = area2 * Fixed(-1);
    if (area3 < 0)
        area3 = area3 * Fixed(-1);
    if (area1 == 0 || area2 == 0 || area3 == 0)
        return false;

    return (area1 + area2 + area3) == totalArea;
}
