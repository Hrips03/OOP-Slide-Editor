#include "addShapeAction.hpp"

addShapeAct::addShapeAct(int slide, std::shared_ptr<Item> item) : m_slideID(slide), m_item(item) {}

std::shared_ptr<IAction> addShapeAct::doAction()
{
    std::shared_ptr<Document> myDocument = Document::getInstance();
    myDocument->addShape(m_slideID, m_item);
    return std::make_shared<removeShapeAct>(m_slideID, m_item);
    //std::cout << "Shape is added successfully to slide " << m_slideNumber << ".\n";
}
