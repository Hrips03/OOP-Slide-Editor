#include "includes/slide.hpp"

bool Slide::operator<(const Slide &other) const
{
    return ID < other.ID;
}

Slide &Slide::operator=(const Slide &other)
{
    if (this != &other)
        ID = other.ID;
    
    return *this;
}