#include "removeShapeAct.hpp"

removeShapeAct::removeShapeAct(int slideNum, int itemNum) : m_slideID(slideNum), m_itemID(itemNum){}

std::shared_ptr<IAction> removeShapeAct::doAction()
{
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Item item = myDocument->slides[m_slideID]->items[m_itemID];
    std::shared_ptr<Item> m_item = std::make_shared<Item>(item);
    if(m_item){
        myDocument->remShape(m_slideID, m_itemID);
        return std::make_shared<addShapeAct>(m_slideID, m_item);
    } 
    return nullptr;
}