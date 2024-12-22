#pragma once
#include <sstream>
#include <iostream>

class IShape
{
public:
    virtual void print(std::ostream& out, size_t shapeIndex) const = 0;
    virtual void draw() = 0;
    virtual ~IShape() = default;
};