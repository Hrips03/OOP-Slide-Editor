#include "./includes/addShapeCmd.hpp"
#include "../../Application.hpp"

addShape ::addShape(int slideNum, std::shared_ptr<Item> item)
    : m_slideNumber(slideNum), m_item(item)
{
    //m_editor = std::shared_ptr<Editor>(new Editor());
    m_editor = Application::getInstance()->getEditor();
}

void addShape ::execute()
{
    std::shared_ptr<IAction> action = std::make_shared<addShapeAct>(m_slideNumber, m_item);
    m_editor->process(action);
}

std::shared_ptr<ICommand> addShape::clone() const
{
    return std::make_shared<addShape>(*this);
}