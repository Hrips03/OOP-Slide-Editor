#include "./includes/addSlideCmd.hpp"

addSlide::addSlide(int pos) : m_position(pos) {}

void addSlide ::execute()
{
    std::shared_ptr<Slide> newSlide = std::make_shared<Slide>();
    std::shared_ptr<IAction> action = std::make_shared<addSlideAct>(newSlide, m_position);
    Editor::getInstance()->process(action);
}

std::shared_ptr<ICommand> addSlide::clone() const
{
    return std::make_shared<addSlide>(*this);
}