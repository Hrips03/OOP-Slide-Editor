#include "./includes/printSlidesCmd.hpp"

printSlides::printSlides(){
    m_doc = std::shared_ptr<Document>(new Document());
    //m_doc = Application::getInstance()->getDocument();
}

void printSlides :: execute(){
    //std::shared_ptr<Document> myDocument = Document::getInstance();
    m_doc->printSlides();
}

std::shared_ptr<ICommand> printSlides::clone() const
{
    return std::make_shared<printSlides>(*this);
}