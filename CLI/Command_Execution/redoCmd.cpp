#include "./includes/redoCmd.hpp"
#include "../../Application.hpp"

RedoCmd::RedoCmd(){
    //m_editor = std::shared_ptr<Editor>(new Editor());
    m_editor = Application::getInstance()->getEditor();
}

void RedoCmd ::execute()
{
    m_editor->redo();
}

std::shared_ptr<ICommand> RedoCmd::clone() const
{
    return std::make_shared<RedoCmd>(*this);
}