#pragma once
#include <iostream>
#include <sstream>

class Triangle
{
public:
    double x, y;
    std::string color;

    Triangle(double x, double y, const std::string &color) : x(x), y(y), color(color) {}
    Triangle(const Triangle &other) : x(other.x), y(other.y), color(other.color) {}

    Triangle &operator=(const Triangle &other);
    void print(std::ostream &out) const;
};