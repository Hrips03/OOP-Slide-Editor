#include "./includes/remShapeCmd.hpp"

removeShape ::removeShape(int slideNum, Shape::ShapeType type, Shape::Geometry geom, Shape::Attributes attrs)
    : m_slideNumber(slideNum), m_shapeType(type), m_geometry(geom), m_attributes(attrs) {}

std::shared_ptr<ICommand> removeShape::clone() const
{
    return std::make_shared<removeShape>(*this);
}

void removeShape :: execute(){
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.remShape(m_slideNumber, m_shapeType, m_geometry, m_attributes);
    //std::cout << "Shape is removed successfully from slide " << m_slideNumber << ".\n";
}