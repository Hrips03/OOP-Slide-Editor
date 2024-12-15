#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Document/includes/document.hpp"

class addShape : public ICommand
{
    int m_slideNumber; 
    Item::ShapeType m_shapeType;
    Item::Geometry m_geometry;
    Item::Attributes m_attributes;
public:
    addShape(int slideNum, Item::ShapeType type, Item::Geometry geom, Item::Attributes attrs);
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};