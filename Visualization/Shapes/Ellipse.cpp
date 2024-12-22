#include "Ellipse.hpp"

Ellipse::Ellipse(Item item) : m_item(item) {}

void Ellipse::print(std::ostream& out, size_t shapeIndex) const
{
    int width = m_item.geom.width;
    int height = m_item.geom.height;

    float centerX = m_item.geom.x + width / 2;
    float centerY = m_item.geom.y + height / 2;

    // Calculate the radii
    float radiusX = width / 2; // Horizontal radius
    float radiusY = height / 2; // Vertical radius


    out << "  Shape " << shapeIndex << ": Ellipse"
            << " | CenterX: " << centerX 
            << " | CenterY: " << centerY 
            << " | Horizontal Radius (a): " << width 
            << " | Vertical Radius (b): "  << height 
            << " | Color: " << m_item.attribs.color 
            << " | Outline Color: " << m_item.attribs.outlineColor << "\n";
}

void Ellipse:: draw(){
    
}