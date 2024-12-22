#include "./includes/undoCmd.hpp"

UndoCmd::UndoCmd(){
    std::shared_ptr<Editor> m_editor = std::shared_ptr<Editor>(new Editor());
}
void UndoCmd ::execute()
{
    m_editor->undo();
}

std::shared_ptr<ICommand> UndoCmd::clone() const
{
    return std::make_shared<UndoCmd>(*this);
}