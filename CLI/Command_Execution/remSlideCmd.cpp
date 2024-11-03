#include "./includes/remSlideCmd.hpp"

removeSlide::removeSlide(int pos) : m_position(pos) {}

void removeSlide ::execute()
{
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.remSlide(m_position);
    //std::cout << "Removing the slide.\n";
}

std::shared_ptr<ICommand> removeSlide::clone() const
{
    return std::make_shared<removeSlide>(*this);
}