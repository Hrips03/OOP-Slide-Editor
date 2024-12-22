#include "./includes/remSlideCmd.hpp"

removeSlide::removeSlide(int pos) : m_position(pos){
    std::shared_ptr<Editor> m_editor = std::shared_ptr<Editor>(new Editor());
}

void removeSlide ::execute()
{
    std::shared_ptr<IAction> action = std::make_shared<removeSlideAct>(m_position);
    m_editor->process(action);
}

std::shared_ptr<ICommand> removeSlide::clone() const
{
    return std::make_shared<removeSlide>(*this);
}