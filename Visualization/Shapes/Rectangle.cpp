#include "Rectangle.hpp"

Rectangle::Rectangle(Item item) : m_item(item) {}

void Rectangle::print(std::ostream& out, size_t shapeIndex) const
{
    out << "  Shape " << shapeIndex << ": Rectangle"
            << " | PositionX: " << m_item.geom.x 
            << " | PositionY: " << m_item.geom.y 
            << " | Width: " << m_item.geom.width 
            << " | Height: "  << m_item.geom.height 
            << " | Color: " << m_item.attribs.color 
            << " | Outline Color: " << m_item.attribs.outlineColor << "\n";
}

void Rectangle:: draw(){
    
}