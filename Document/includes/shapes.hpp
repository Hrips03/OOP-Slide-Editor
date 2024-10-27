#pragma once
#include <string>

struct Shape
{
    enum class ShapeType
    {
        Circle,
        Rectangle,
        Triangle
    };

    struct Geometry
    {
        int x;
        int y;
        int size;
    };

    struct Attributes
    {
        std::string color;         // Color of the shape
        std::string outlineColor;  // Outline color of the shape
    };

    ShapeType type; 
    Geometry geom;
    Attributes attribs;
};