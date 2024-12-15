#include "./includes/remSlideCmd.hpp"

removeSlide::removeSlide(int pos) : m_position(pos) {}

void removeSlide ::execute()
{
    std::shared_ptr<IAction> action = std::make_shared<removeSlideAct>(m_position);
    Editor{}.process(action);
}

std::shared_ptr<ICommand> removeSlide::clone() const
{
    return std::make_shared<removeSlide>(*this);
}