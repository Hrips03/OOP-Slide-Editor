#include "./includes/printSlidesCmd.hpp"

printSlides::printSlides(){
    std::shared_ptr<Document> m_doc = std::shared_ptr<Document>(new Document());
}

void printSlides :: execute(){
    //std::shared_ptr<Document> myDocument = Document::getInstance();
    m_doc->printSlides();
}

std::shared_ptr<ICommand> printSlides::clone() const
{
    return std::make_shared<printSlides>(*this);
}