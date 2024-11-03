#include "editor.hpp"

void Editor::addSlide(int position)
{
    if (position >= 0 && position <= static_cast<int>(m_doc->slides.size()))
    {
        m_doc->slides.insert(m_doc->slides.begin() + position, Slide{});
        std::cout << "Slide is succesfully added at position " << position << ".\n" << std::endl;
    }
    else
    {
        std::cout << "Position " << position << " is out of bounds. Adding at position " << m_doc->slides.size() << "." << std::endl;
        std::cout << "Slide is succesfully added at position " << m_doc->slides.size() << ".\n" << std::endl;
        m_doc->slides.push_back(Slide{});
    }
}

void Editor::remSlide(int position)
{
    if (position >= 0 && position < static_cast<int>(m_doc->slides.size()))
    {
        m_doc->slides.erase(m_doc->slides.begin() + position);
        std::cout << "Slide is succesfully removed from position " << position << ".\n" << std::endl;
    }
    else
        std::cerr << "Error: Position " << position << " is out of bounds.\n" << std::endl;
}

void Editor::addShape(int slideNumber, Shape::ShapeType shapeType, Shape::Geometry geometry, Shape::Attributes attributes)
{
    if (slideNumber < 0 || slideNumber >= m_doc->slides.size())
    {
        std::cerr << "Invalid slide number.\n" << std::endl;
        return;
    }
    else
    {
        Shape shape;
        shape.type = shapeType;
        shape.geom = geometry;
        shape.attribs = attributes;
        m_doc->slides[slideNumber].shapes.push_back(shape);
        std::cout << "Shape added to slide " << slideNumber << " successfully.\n" << std::endl;
    }
}

void Editor::remShape(int slideNumber, Shape::ShapeType shapeType, Shape::Geometry geometry, Shape::Attributes attributes)
{
    if (slideNumber < 0 || slideNumber >= m_doc->slides.size())
    {
        std::cerr << "Invalid slide number.\n" << std::endl;
        return;
    }
    else
    {
        auto &shapes = m_doc->slides[slideNumber].shapes;
        bool shapeFound = false;
        for (auto it = shapes.begin(); it != shapes.end();)
        {
            if (it->type == shapeType &&
                it->geom.x == geometry.x &&
                it->geom.y == geometry.y &&
                it->geom.height == geometry.height &&
                it->geom.width == geometry.width &&
                it->attribs.color == attributes.color &&
                it->attribs.outlineColor == attributes.outlineColor)
            {
                it = shapes.erase(it);
                shapeFound = true;
                std::cout << "Shape removed from slide " << slideNumber << " successfully.\n" << std::endl;
            }
            else
            {
                ++it;
            }
        }

        if (!shapeFound)
            std::cout << "No shape found with the specified attributes on slide " << slideNumber << ".\n" << std::endl;
    }
}

void Editor::printHelp()
{
    std::string help = "Commands prototypes:\n"
                       "add slide -pos <number> : adding a slide\n"
                       "remove slide -pos <number> : removing a slide\n"
                       "print slide -pos <number> : printing a slide\n"
                       "add shape -type <shapeType> -x <number> -y <number> -height <number> -width <number> -slide <number> -col <colorName> -outlineColor <outlineColorName>: adding a shape (color is optional)\n"
                       "remove shape -type <shapeType> -x <number> -y <number> -height <number> -width <number> -slide <number> -col <colorName> -outlineColor <outlineColorName> : removing a shape (color is optional)\n"
                       "help : displaying this help message\n"
                       "exit : exiting the application\n";

    std::cout << help << std::endl;
}

void Editor::printSlide(int pos)
{
    if (pos < 0 || pos >= m_doc->slides.size())
    {
        std::cout << "Error: Invalid position " << pos << ". Cannot remove slide.\n" << std::endl;
        return;
    }

    auto slideIt = m_doc->slides.begin();
    std::advance(slideIt, pos);

    Visualizer visual;
    visual.printSlide(std::cout, slideIt, pos);
}

void Editor::printSlides()
{
    if (m_doc->slides.size() > 0)
    {
        Visualizer visual;
        visual.printSlides(std::cout, m_doc->slides);
    }
    else
        std::cout << "There are no slides to be printed\n" <<std::endl;
}

