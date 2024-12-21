#include "./includes/addShapeCmd.hpp"

addShape ::addShape(int slideNum, std::shared_ptr<Item> item)
    : m_slideNumber(slideNum), m_item(item) {}


void addShape ::execute()
{ 
    std::shared_ptr<Item> newItem = m_item;
    std::shared_ptr<IAction> action = std::make_shared<addShapeAct>(m_slideNumber, newItem);
    Editor::getInstance()->process(action);
}

std::shared_ptr<ICommand> addShape::clone() const
{
    return std::make_shared<addShape>(*this);
}