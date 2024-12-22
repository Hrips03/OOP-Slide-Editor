#include "Triangle.hpp"

Triangle::Triangle(Item item) : m_item(item) {}

void Triangle::print(std::ostream& out, size_t shapeIndex) const
{
    float topX = m_item.geom.x + m_item.geom.width / 2;    // Top vertex (midpoint of the top edge)
    float topY = m_item.geom.y;
    float bottomLeftX = m_item.geom.x;         // Bottom-left vertex
    float bottomLeftY = m_item.geom.y + m_item.geom.height;
    float bottomRightX = m_item.geom.x + m_item.geom.width; // Bottom-right vertex
    float bottomRightY = m_item.geom.y + m_item.geom.height;

    // Calculate the lengths of the sides
    float side1 = std::sqrt((topX - bottomLeftX) * (topX - bottomLeftX) + (topY - bottomLeftY) * (topY - bottomLeftY));  // Left side
    float side2 = std::sqrt((topX - bottomRightX) * (topX - bottomRightX) + (topY - bottomRightY) * (topY - bottomRightY)); // Right side
    float side3 = std::sqrt((bottomLeftX - bottomRightX) * (bottomLeftX - bottomRightX) + (bottomLeftY - bottomRightY) * (bottomLeftY - bottomRightY)); // Base


    out << "  Shape " << shapeIndex << ": Triangle"
            << " | Side 1 (Left): " << side1
            << " | Side 2 (Rigth): " << side2
            << " | Side 3 (Base): " << side3
            << " | Color: " << m_item.attribs.color 
            << " | Outline Color: " << m_item.attribs.outlineColor << "\n";
}


void Triangle:: draw(){
    
}