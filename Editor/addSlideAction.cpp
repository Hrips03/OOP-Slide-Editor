#include "addSlideAction.hpp"
#include "../Application.hpp"

addSlideAct::addSlideAct(std::shared_ptr<Slide> newSlide) : m_slide(newSlide) {
    //m_doc = std::shared_ptr<Document>(new Document());
    m_doc = Application::getInstance()->getDocument();
}

std::shared_ptr<IAction> addSlideAct::doAction()
{
    //std::shared_ptr<Document> myDocument = Document::getInstance();
    int pos = m_slide->getPosition();
    if(m_doc->slides.size() < pos){
        m_slide->setPosition(m_doc->slides.size());
        pos = m_doc->slides.size();
    }

    m_doc->addSlide(m_slide);
    return std::make_shared<removeSlideAct>(pos);
}
