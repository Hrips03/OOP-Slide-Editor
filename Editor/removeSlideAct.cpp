#include "removeSlideAct.hpp"

removeSlideAct::removeSlideAct(int pos) : m_pos(pos) {}

std::shared_ptr<IAction> removeSlideAct::doAction()
{
    std::shared_ptr<Document> myDocument = Document::getInstance();
    myDocument->remSlide(m_pos);
    return std::make_shared<addSlideAct>(nullptr);
}
