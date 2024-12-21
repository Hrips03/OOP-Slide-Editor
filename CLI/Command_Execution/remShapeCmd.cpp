#include "./includes/remShapeCmd.hpp"

removeShape ::removeShape(int slideNum, int itemNum)
    : m_slideNumber(slideNum), m_itemNum(itemNum) {}

std::shared_ptr<ICommand> removeShape::clone() const
{
    return std::make_shared<removeShape>(*this);
}

void removeShape ::execute()
{
    std::shared_ptr<IAction> action = std::make_shared<removeShapeAct>(m_slideNumber, m_itemNum);
    Editor::getInstance()->process(action);
}