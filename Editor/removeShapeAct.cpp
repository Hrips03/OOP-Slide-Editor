#include "removeShapeAct.hpp"

removeShapeAct::removeShapeAct(int slide, std::shared_ptr<Item> item) : m_slideID(slide), m_item(item) {}

std::shared_ptr<IAction> removeShapeAct::doAction()
{
    std::shared_ptr<Document> myDocument = Document::getInstance();
    myDocument->remShape(m_slideID, m_item);
    return std::make_shared<addShapeAct>(m_slideID, m_item);
}
