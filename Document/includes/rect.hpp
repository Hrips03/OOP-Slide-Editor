#pragma once
#include <iostream>
#include <sstream>
class Rect
{
public:
    double x, y;
    std::string color;

    Rect(double x, double y, const std::string &color) : x(x), y(y), color(color) {}
    Rect(const Rect &other) : x(other.x), y(other.y), color(other.color) {}

    Rect &operator=(const Rect &other);
    void print(std::ostream &out) const;
};