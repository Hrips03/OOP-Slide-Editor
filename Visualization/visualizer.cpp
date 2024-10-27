#include "visualizer.hpp"

void Visualizer::printSlide(std::ostream &out, std::vector<Slide>::iterator slideIt)
{
    out << "Slide:\n";
    for (const auto &shape : slideIt->shapes)
    {
        out << "  Shape: ";
        switch (shape.type)
        {
        case Shape::ShapeType::Circle:
            out << "Circle";
            break;
        case Shape::ShapeType::Rectangle:
            out << "Rectangle";
            break;
        case Shape::ShapeType::Triangle:
            out << "Triangle";
            break;
        }
        out << " | Position: (" << shape.geom.x << ", " << shape.geom.y << ")"
            << " | Size: " << shape.geom.size
            << " | Color: " << shape.attribs.color
            << " | Outline Color: " << shape.attribs.outlineColor << "\n";
    }
    out << "---------------------\n";
}
