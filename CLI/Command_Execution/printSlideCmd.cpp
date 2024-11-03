#include "./includes/printSlideCmd.hpp"

printSlide::printSlide(int pos) : m_position(pos) {}

void printSlide :: execute(){
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.printSlide(m_position);
    //std::cout << "Printing the slide.\n";
}

std::shared_ptr<ICommand> printSlide::clone() const
{
    return std::make_shared<printSlide>(*this);
}