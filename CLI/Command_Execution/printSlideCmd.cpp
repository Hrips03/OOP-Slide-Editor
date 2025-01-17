#include "./includes/printSlideCmd.hpp"
#include "../../Application.hpp"

printSlide::printSlide(int pos) : m_position(pos) {
    //m_doc = std::shared_ptr<Document>(new Document());
    m_doc = Application::getInstance()->getDocument();
}

void printSlide :: execute(){
    //std::shared_ptr<Document> myDocument = Document::getInstance();
    m_doc->printSlide(m_position);
}

std::shared_ptr<ICommand> printSlide::clone() const
{
    return std::make_shared<printSlide>(*this);
}