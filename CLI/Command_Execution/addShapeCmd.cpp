#include "./includes/addShapeCmd.hpp"

addShape ::addShape(int slideNum, std::shared_ptr<Item> item)
    : m_slideNumber(slideNum), m_item(item) {
        std::shared_ptr<Editor> m_editor = std::shared_ptr<Editor>(new Editor());
}


void addShape ::execute()
{ 
    std::shared_ptr<Item> newItem = m_item;
    std::shared_ptr<IAction> action = std::make_shared<addShapeAct>(m_slideNumber, newItem);
    m_editor->process(action);
}

std::shared_ptr<ICommand> addShape::clone() const
{
    return std::make_shared<addShape>(*this);
}