#include "visualizer.hpp"
#include "./Shapes/IShape.hpp"
#include "./Shapes/Ellipse.hpp"
#include "./Shapes/Rectangle.hpp"
#include "./Shapes/Triangle.hpp"

void Visualizer::printSlide(std::ostream &out, std::shared_ptr<Slide> slide, size_t slideIndex)
{
    out << "Slide " << slideIndex << ":\n";  
    size_t shapeIndex = 0; 
    
    for (auto shape : slide->items)
    {       
        // Create the appropriate shape based on its type
        std::shared_ptr<IShape> myShape = nullptr;

        switch (shape.type) {
            case Item::ShapeType::Ellipse:
                myShape = std::make_shared<Ellipse>(shape); 
                break;
            case Item::ShapeType::Rectangle:
                myShape = std::make_shared<Rectangle>(shape); 
                break;
            case Item::ShapeType::Triangle:
                myShape = std::make_shared<Triangle>(shape); 
                break;
        }
        
        myShape->print(out, shapeIndex);
        ++shapeIndex; 
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

