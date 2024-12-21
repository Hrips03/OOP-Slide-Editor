#include "./includes/printSlideCmd.hpp"

printSlide::printSlide(int pos) : m_position(pos) {}

void printSlide :: execute(){
    std::shared_ptr<Document> myDocument = Document::getInstance();
    myDocument->printSlide(m_position);
}

std::shared_ptr<ICommand> printSlide::clone() const
{
    return std::make_shared<printSlide>(*this);
}