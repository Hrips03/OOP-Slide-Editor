#include "./includes/remShapeCmd.hpp"
#include "../../Application.hpp"

removeShape ::removeShape(int slideNum, int itemNum)
    : m_slideNumber(slideNum), m_itemNum(itemNum) {
    //m_editor = std::shared_ptr<Editor>(new Editor());
    m_editor = Application::getInstance()->getEditor();
}

void removeShape ::execute()
{
    std::shared_ptr<IAction> action = std::make_shared<removeShapeAct>(m_slideNumber, m_itemNum);
    m_editor->process(action);
}

std::shared_ptr<ICommand> removeShape::clone() const
{
    return std::make_shared<removeShape>(*this);
}