#include "./includes/remSlideCmd.hpp"
#include "../../Application.hpp"

removeSlide::removeSlide(int pos) : m_position(pos){
    //m_editor = std::shared_ptr<Editor>(new Editor());
    m_editor = Application::getInstance()->getEditor();
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