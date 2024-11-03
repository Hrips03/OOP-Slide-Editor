#include "./includes/addShapeCmd.hpp"

addShape ::addShape(int slideNum, Shape::ShapeType type, Shape::Geometry geom, Shape::Attributes attrs)
    : m_slideNumber(slideNum), m_shapeType(type), m_geometry(geom), m_attributes(attrs) {}

void addShape ::execute()
{
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.addShape(m_slideNumber, m_shapeType, m_geometry, m_attributes);
    //std::cout << "Shape is added successfully to slide " << m_slideNumber << ".\n";
}

std::shared_ptr<ICommand> addShape::clone() const
{
    return std::make_shared<addShape>(*this);
}