#include "visualizer.hpp"

void Visualizer::printSlide(std::ostream &out, std::shared_ptr<Slide> slide, size_t slideIndex)
{
    out << "Slide " << slideIndex << ":\n";  
    size_t shapeIndex = 0; // Counter for shape index
    
    for (const auto& shape : slide->items)
    {
        out << "  Shape " << shapeIndex << ": "; // Print the shape's index
        switch (shape.type)
        {
        case Item::ShapeType::Ellipse:
            out << "Ellipse";
            break;
        case Item::ShapeType::Rectangle:
            out << "Rectangle";
            break;
        case Item::ShapeType::Triangle:
            out << "Triangle";
            break;
        }
        out << " | X: " << shape.geom.x 
            << " | Y: " << shape.geom.y 
            << " | Height: " << shape.geom.height
            << " | Width: " << shape.geom.width
            << " | Color: " << shape.attribs.color
            << " | Outline Color: " << shape.attribs.outlineColor << "\n";
        ++shapeIndex; // Increment the shape index
    }
    out << "---------------------\n";
}


void Visualizer::printSlides(std::ostream &out, const std::vector<std::shared_ptr<Slide>>& slides)
{
    for (size_t i = 0; i < slides.size(); ++i)
    {
        printSlide(out, slides[i], i); 
    }
}

