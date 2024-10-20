#include "./includes/rect.hpp"

void Rect::print(std::ostream &out) const{
    out << "  rectangle -pos1 " << x << " -pos2 " << y << " -col " << color << std::endl;
}

Rect& Rect::operator=(const Rect &other)
{
    if (this != &other)
    { 
        x = other.x;
        y = other.y;
        color = other.color;
    }
    return *this; 
}