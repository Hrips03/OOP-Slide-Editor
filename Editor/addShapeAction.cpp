#include "addShapeAction.hpp"
#include "../Application.hpp"

addShapeAct::addShapeAct(int slide, std::shared_ptr<Item> item) : m_slideID(slide), m_item(item) {
    //m_doc = std::shared_ptr<Document>(new Document());
    m_doc = Application::getInstance()->getDocument();
}
 
std::shared_ptr<IAction> addShapeAct::doAction()
{
    auto &shapes = m_doc->slides[m_slideID]->items;
    int itemID = 0;
    for (size_t i = 0; i < shapes.size(); ++i)
    {
        if (shapes[i].type == m_item->type &&
            shapes[i].geom.x == m_item->geom.x &&
            shapes[i].geom.y == m_item->geom.y &&
            shapes[i].geom.height == m_item->geom.height &&
            shapes[i].geom.width == m_item->geom.width &&
            shapes[i].attribs.color == m_item->attribs.color &&
            shapes[i].attribs.outlineColor == m_item->attribs.outlineColor)
        {
            itemID = i;
        }
    }

    m_doc->addShape(m_slideID, m_item); 
    return std::make_shared<removeShapeAct>(m_slideID, itemID);
}
