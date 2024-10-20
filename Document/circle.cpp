#include "./includes/circle.hpp"

void Circle::print(std::ostream &out) const
{
    out << "  circle -pos1 " << x << " -pos2 " << y << " -col " << color << std::endl;
}

Circle& Circle::operator=(const Circle &other)
{
    if (this != &other)
    { 
        x = other.x;
        y = other.y;
        color = other.color;
    }
    return *this; 
}
