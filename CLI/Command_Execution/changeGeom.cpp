#include "./includes/changeGeom.hpp"

changeGeometry ::changeGeometry(int slideNum, int itemNum, Item::Geometry itemGeom, Item::Attributes itemAttribs)
    : m_slideNumber(slideNum), m_itemNum(itemNum), m_itemGeom(itemGeom), m_itemAttribs(itemAttribs) {
    m_editor = std::shared_ptr<Editor>(new Editor());
    //m_editor = Application::getInstance()->getEditor();
}


void changeGeometry ::execute()
{ 
    //std::shared_ptr<Item> newItem = m_item;
    std::shared_ptr<IAction> action = std::make_shared<changeGeometryAct>(m_slideNumber, m_itemNum, m_itemGeom, m_itemAttribs);
    m_editor->process(action);
}

std::shared_ptr<ICommand> changeGeometry::clone() const
{
    return std::make_shared<changeGeometry>(*this);
}