#include "visualizer.hpp"
#include "./Shapes/IShape.hpp"
#include "./Shapes/Ellipse.hpp"
#include "./Shapes/Rectangle.hpp"
#include "./Shapes/Triangle.hpp"
#include <unordered_map>
#include <unordered_set>
#include <functional>

std::unordered_map<Item::ShapeType, std::function<std::shared_ptr<IShape>(const Item &)>> prototypeFactory = {
    {Item::ShapeType::Ellipse, [](const Item &shape)
     {
        return std::make_shared<Ellipse>(shape);
     }},

    {Item::ShapeType::Triangle, [](const Item &shape)
     {
        return std::make_shared<Triangle>(shape);
     }},

    {Item::ShapeType::Rectangle, [](const Item &shape)
     {
        return std::make_shared<Rectangle>(shape);
     }}
};

void Visualizer::printSlide(std::ostream &out, std::shared_ptr<Slide> slide, size_t slideIndex)
{
    out << "Slide " << slideIndex << ":\n";
    size_t shapeIndex = 0;

    for (auto shape : slide->items)
    {
        // Create the appropriate shape based on its type
        std::shared_ptr<IShape> myShape = prototypeFactory.at(shape.type)(shape);
        myShape->print(out, shapeIndex);
        ++shapeIndex;
    }
    out << "---------------------\n";
}

void Visualizer::printSlides(std::ostream &out, const std::vector<std::shared_ptr<Slide>> &slides)
{
    for (size_t i = 0; i < slides.size(); ++i)
    {
        printSlide(out, slides[i], i);
    }
}
