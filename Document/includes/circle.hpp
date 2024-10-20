#pragma once
#include <iostream>
#include <sstream>

class Circle
{
public:
    double x, y;
    std::string color;

    Circle(double x, double y, const std::string &color) : x(x), y(y), color(color) {}
    Circle(const Circle &other) : x(other.x), y(other.y), color(other.color) {}

    Circle &operator=(const Circle &other);

    void print(std::ostream &out) const;
};
