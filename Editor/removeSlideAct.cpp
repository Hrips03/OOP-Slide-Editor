#include "removeSlideAct.hpp"

removeSlideAct::removeSlideAct(int pos) : m_pos(pos) {
    std::shared_ptr<Document> m_doc = std::shared_ptr<Document>(new Document());
}

std::shared_ptr<IAction> removeSlideAct::doAction()
{
    //std::shared_ptr<Document> myDocument = Document::getInstance();
    auto m_slide = m_doc->slides[m_pos];
    if(m_slide){
        m_doc->remSlide(m_pos);
        return std::make_shared<addSlideAct>(m_slide);
    }
    return nullptr;
}
