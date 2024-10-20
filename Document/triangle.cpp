#include "./includes/triangle.hpp"

void Triangle::print(std::ostream &out) const{
    out << "  triangle -pos1 " << x << " -pos2 " << y << " -col " << color << std::endl;
}

Triangle& Triangle::operator=(const Triangle &other)
{
    if (this != &other)
    { 
        x = other.x;
        y = other.y;
        color = other.color;
    }
    return *this; 
}