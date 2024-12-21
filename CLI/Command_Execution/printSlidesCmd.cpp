#include "./includes/printSlidesCmd.hpp"

void printSlides :: execute(){
    std::shared_ptr<Document> myDocument = Document::getInstance();
    myDocument->printSlides();
}

std::shared_ptr<ICommand> printSlides::clone() const
{
    return std::make_shared<printSlides>(*this);
}