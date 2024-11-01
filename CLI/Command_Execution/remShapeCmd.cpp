#include "./includes/remShapeCmd.hpp"

removeShape::removeShape(const std::vector<std::string> &args) : arguments(args) {}

std::unique_ptr<ICommand> removeShape::clone() const
{
    return std::make_unique<removeShape>(*this);
}