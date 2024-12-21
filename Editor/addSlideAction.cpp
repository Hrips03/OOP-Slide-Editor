#include "addSlideAction.hpp"

addSlideAct::addSlideAct(std::shared_ptr<Slide> newSlide) : m_slide(newSlide) {}

std::shared_ptr<IAction> addSlideAct::doAction()
{
    std::shared_ptr<Document> myDocument = Document::getInstance();
    int pos = m_slide->getPosition();
    if(myDocument->slides.size() < pos){
        m_slide->setPosition(myDocument->slides.size());
        pos = myDocument->slides.size();
    }

    myDocument->addSlide(m_slide);
    return std::make_shared<removeSlideAct>(pos);
}
