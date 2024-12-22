#include "./includes/addSlideCmd.hpp"

addSlide::addSlide(int pos) : m_position(pos) {
    std::shared_ptr<Editor> m_editor = std::shared_ptr<Editor>(new Editor());
} 

void addSlide ::execute()
{
    std::shared_ptr<Slide> newSlide = std::make_shared<Slide>(m_position);
    std::shared_ptr<IAction> action = std::make_shared<addSlideAct>(newSlide);
    m_editor->process(action);
}

std::shared_ptr<ICommand> addSlide::clone() const
{
    return std::make_shared<addSlide>(*this);
}