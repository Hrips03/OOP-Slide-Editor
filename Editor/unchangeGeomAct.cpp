#include "unchangeGeomAct.hpp"

unchangeGeometryAct::unchangeGeometryAct(int slideNum, int itemNum, Item::Geometry itemGeom, Item::Attributes itemAttribs)
    : m_slideNumber(slideNum), m_itemNum(itemNum), m_itemGeom(itemGeom), m_itemAttribs(itemAttribs)
{
    m_doc = std::shared_ptr<Document>(new Document());
    //m_doc = Application::getInstance()->getDocument();
}

std::shared_ptr<IAction> unchangeGeometryAct::doAction()
{
    auto &shape = m_doc->slides[m_slideNumber]->items[m_itemNum];
    m_doc->changeGeom(m_slideNumber, m_itemNum, m_itemGeom, m_itemAttribs);
    return std::make_shared<changeGeometryAct>(m_slideNumber, m_itemNum, shape.geom, shape.attribs);
}
