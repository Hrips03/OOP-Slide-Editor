#include "./includes/remShapeCmd.hpp"

removeShape ::removeShape(int slideNum, std::shared_ptr<Item> item)
    : m_slideNumber(slideNum), m_item(item) {}

std::shared_ptr<ICommand> removeShape::clone() const
{
    return std::make_shared<removeShape>(*this);
}

void removeShape :: execute(){
    std::shared_ptr<IAction> action = std::make_shared<removeShapeAct>(m_slideNumber, m_item);
    Editor::getInstance()->process(action);
}