#include "visualizer.hpp"

#include "visualizer.hpp"

void Visualizer::printSlide(std::ostream &out, std::vector<Slide>::iterator slideIt, size_t slideIndex)
{
    out << "Slide " << slideIndex << ":\n";  
    for (const auto &shape : slideIt->shapes)
    {
        out << "  Shape: ";
        switch (shape.type)
        {
        case Shape::ShapeType::Ellipse:
            out << "Ellipse";
            break;
        case Shape::ShapeType::Rectangle:
            out << "Rectangle";
            break;
        case Shape::ShapeType::Triangle:
            out << "Triangle";
            break;
        }
        out << " | Position: (" << shape.geom.x << ", " << shape.geom.y << ")"
            << " | Height: " << shape.geom.height
            << " | Width: " << shape.geom.width
            << " | Color: " << shape.attribs.color
            << " | Outline Color: " << shape.attribs.outlineColor << "\n";
    }
    out << "---------------------\n";
}



void Visualizer::printSlides(std::ostream &out, std::vector<Slide> &slides)
{
    for (size_t i = 0; i < slides.size(); ++i)
    {
        printSlide(out, slides.begin() + i, i); 
    }
}

