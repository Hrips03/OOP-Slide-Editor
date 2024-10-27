#include "editor.hpp"

void Editor::addSlide(int position)
{
    if (position >= 0 && position <= static_cast<int>(m_doc->slides.size()))
        m_doc->slides.insert(m_doc->slides.begin() + position, Slide{});
    else
        std::cerr << "Error: Position " << position << " is out of bounds." << std::endl;
}


void Editor::remSlide(int position)
{
    if (position >= 0 && position < static_cast<int>(m_doc->slides.size()))
        m_doc->slides.erase(m_doc->slides.begin() + position);
    else
        std::cerr << "Error: Position " << position << " is out of bounds." << std::endl;
}


void Editor::addShape(int slideNumber, Shape::ShapeType shapeType, Shape::Geometry geometry, Shape::Attributes attributes)
{
    if (slideNumber < 0 || slideNumber >= m_doc->slides.size())
    {
        std::cerr << "Invalid slide number." << std::endl;
        return;
    }

    Shape shape;
    shape.type = shapeType;
    shape.geom = geometry;
    shape.attribs = attributes;

    m_doc->slides[slideNumber].shapes.push_back(shape);
    std::cout << "Shape added to slide " << slideNumber << " successfully." << std::endl;
}


void Editor::remShape(int slideNumber, Shape::ShapeType shapeType, Shape::Geometry geometry, Shape::Attributes attributes)
{
    if (slideNumber < 0 || slideNumber >= m_doc->slides.size())
    {
        std::cerr << "Invalid slide number." << std::endl;
        return;
    }

    auto &shapes = m_doc->slides[slideNumber].shapes;
    bool shapeFound = false;
    for (auto it = shapes.begin(); it != shapes.end();)
    {
        if (it->type == shapeType &&
            it->geom.x == geometry.x &&
            it->geom.y == geometry.y &&
            it->geom.size == geometry.size &&
            it->attribs.color == attributes.color &&
            it->attribs.outlineColor == attributes.outlineColor)
        {
            it = shapes.erase(it);
            shapeFound = true;
            std::cout << "Shape removed from slide " << slideNumber << " successfully." << std::endl;
        }
        else
        {
            ++it;
        }
    }

    if (!shapeFound)
        std::cout << "No shape found with the specified attributes on slide " << slideNumber << "." << std::endl;
    
}


void Editor::printHelp()
{
    std::string help = "Commands prototypes:\n"
                       "add slide -pos <number> : adding a slide\n"
                       "remove slide -pos <number> : removing a slide\n"
                       "print slide -pos <number> : printing a slide\n"
                       "add shape -type <shapeType> -x <number> -y <number> -slide <number> -col <colorName> -outlineColor <outlineColorName>: adding a shape (color is optional)\n"
                       "remove shape -type <shapeType> -x <number> -y <number> -slide <number> -col <colorName> -outlineColor <outlineColorName> : removing a shape (color is optional)\n"
                       "help : displaying this help message\n"
                       "exit : exiting the application";

    std::cout << help << std::endl;
}