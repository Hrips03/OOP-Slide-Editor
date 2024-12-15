#pragma once
#include <string>

struct Item
{
    enum class ShapeType
    {
        Ellipse,
        Rectangle,
        Triangle
    };

    struct Geometry
    {
        double x;
        double y;
        double height;
        double width;
    };

    struct Attributes
    {
        std::string color;         
        std::string outlineColor;  
        // Attributes(const std::string& col = "white", const std::string& outlineCol = "black")
        //     : color(col), outlineColor(outlineCol) {}
    };

    ShapeType type; 
    Geometry geom;
    Attributes attribs;
};