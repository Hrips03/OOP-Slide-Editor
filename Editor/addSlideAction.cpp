#include "addSlideAction.hpp"

addSlideAct::addSlideAct(std::shared_ptr<Slide> newSlide, int pos) : m_slide(newSlide), m_pos(pos) {}

std::shared_ptr<IAction> addSlideAct::doAction()
{
    std::shared_ptr<Document> myDocument = Document::getInstance();
    myDocument->addSlide(m_pos);
    return std::make_shared<removeSlideAct>(m_pos);
}
