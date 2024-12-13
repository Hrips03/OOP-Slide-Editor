#include "includes/document.hpp"

Document::Document()
{
    std::cout << "Instance of Document is created!\n";
}

std::shared_ptr<Document> Document::getInstance()
{
    if (!Document::instance)
    {
        Document::instance = std::shared_ptr<Document>(new Document());
    }
    return Document::instance;
}

std::shared_ptr<Document> Document::instance = nullptr;


void Document::addSlide(int position)
{
    if (position >= 0 && position <= static_cast<int>(slides.size()))
    {
        slides.insert(slides.begin() + position, Slide{});
        std::cout << "Slide is succesfully added at position " << position << ".\n" << std::endl;
    }
    else
    {
        std::cout << "Position " << position << " is out of bounds. Adding at position " << slides.size() << "." << std::endl;
        std::cout << "Slide is succesfully added at position " << slides.size() << ".\n" << std::endl;
        slides.push_back(Slide{});
    }
}

void Document::remSlide(int position)
{
    if (position >= 0 && position < static_cast<int>(slides.size()))
    {
        slides.erase(slides.begin() + position);
        std::cout << "Slide is succesfully removed from position " << position << ".\n" << std::endl;
    }
    else
        std::cerr << "Error: Position " << position << " is out of bounds.\n" << std::endl;
}

void Document::addShape(int slideNumber, Item::ShapeType shapeType, Item::Geometry geometry, Item::Attributes attributes)
{
    if (slideNumber < 0 || slideNumber >= slides.size())
    {
        std::cerr << "Invalid slide number.\n" << std::endl;
        return;
    }
    else
    {
        Item shape;
        shape.type = shapeType;
        shape.geom = geometry;
        shape.attribs = attributes;
        slides[slideNumber].items.push_back(shape);
        std::cout << "Shape added to slide " << slideNumber << " successfully.\n" << std::endl;
    }
}

void Document::remShape(int slideNumber, Item::ShapeType shapeType, Item::Geometry geometry, Item::Attributes attributes)
{
    if (slideNumber < 0 || slideNumber >= slides.size())
    {
        std::cerr << "Invalid slide number.\n" << std::endl;
        return;
    }
    else
    {
        auto &shapes = slides[slideNumber].items;
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

void Document::printHelp()
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

void Document::printSlide(int pos)
{
    if (pos < 0 || pos >= slides.size())
    {
        std::cout << "Error: Invalid position " << pos << ". Cannot remove slide.\n" << std::endl;
        return;
    }

    auto slideIt = slides.begin();
    std::advance(slideIt, pos);

    Visualizer visual;
    visual.printSlide(std::cout, slideIt, pos);
}

void Document::printSlides()
{
    if (slides.size() > 0)
    {
        Visualizer visual;
        visual.printSlides(std::cout, slides);
    }
    else
        std::cout << "There are no slides to be printed\n" <<std::endl;
}

