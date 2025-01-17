#include "./includes/undoCmd.hpp"
#include "../../Application.hpp"

UndoCmd::UndoCmd()
{
    //m_editor = std::shared_ptr<Editor>(new Editor());
    m_editor = Application::getInstance()->getEditor();
}
void UndoCmd ::execute()
{
    m_editor->undo();
}

std::shared_ptr<ICommand> UndoCmd::clone() const
{
    return std::make_shared<UndoCmd>(*this);
}