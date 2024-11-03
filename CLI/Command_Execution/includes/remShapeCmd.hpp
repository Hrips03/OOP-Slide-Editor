#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Editor/editor.hpp"

class removeShape : public ICommand
{    
    int m_slideNumber;            
    Shape::ShapeType m_shapeType; 
    Shape::Geometry m_geometry;   
    Shape::Attributes m_attributes;
public:
    removeShape(int slideNum, Shape::ShapeType type, Shape::Geometry geom, Shape::Attributes attrs);
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};