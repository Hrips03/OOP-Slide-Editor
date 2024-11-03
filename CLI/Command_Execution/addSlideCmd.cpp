#include "./includes/addSlideCmd.hpp"

addSlide::addSlide(int pos) : m_position(pos) {}

void addSlide ::execute()
{
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.addSlide(m_position);
    //std::cout << "Slide is added successfully.\n";
}

std::shared_ptr<ICommand> addSlide::clone() const
{
    return std::make_shared<addSlide>(*this);
}