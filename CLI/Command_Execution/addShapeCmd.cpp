#include "./includes/addShapeCmd.hpp"

addShape::addShape(const std::vector<std::string> &args) : arguments(args) {}

std::unique_ptr<ICommand> addShape::clone() const
{
    return std::make_unique<addShape>(*this); 
}