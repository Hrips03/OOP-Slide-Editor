#include "removeShapeAct.hpp"

removeShapeAct::removeShapeAct(int slideNum, int itemNum) : m_slideID(slideNum), m_itemID(itemNum){
    std::shared_ptr<Document> m_doc = std::shared_ptr<Document>(new Document());
}

std::shared_ptr<IAction> removeShapeAct::doAction()
{
    Item item = m_doc->slides[m_slideID]->items[m_itemID];
    std::shared_ptr<Item> m_item = std::make_shared<Item>(item);
    if(m_item){
        m_doc->remShape(m_slideID, m_itemID);
        return std::make_shared<addShapeAct>(m_slideID, m_item);
    } 
    return nullptr;
}