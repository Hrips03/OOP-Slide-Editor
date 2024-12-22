#include "./includes/unchangeGeom.hpp"

unchangeGeometry ::unchangeGeometry(int slideNum, int itemNum, Item::Geometry itemGeom, Item::Attributes itemAttribs)
    : m_slideNumber(slideNum), m_itemNum(itemNum), m_itemGeom(itemGeom), m_itemAttribs(itemAttribs) {
        std::shared_ptr<Editor> m_editor = std::shared_ptr<Editor>(new Editor());
}

void unchangeGeometry::execute()
{ 
    std::shared_ptr<IAction> action = std::make_shared<unchangeGeometryAct>(m_slideNumber, m_itemNum, m_itemGeom, m_itemAttribs);
    m_editor->process(action);
}

std::shared_ptr<ICommand> unchangeGeometry::clone() const
{
    return std::make_shared<unchangeGeometry>(*this);
}