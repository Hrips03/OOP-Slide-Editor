#include "./includes/undoCmd.hpp"

void UndoCmd ::execute()
{
    Editor::getInstance()->undo();
}

std::shared_ptr<ICommand> UndoCmd::clone() const
{
    return std::make_shared<UndoCmd>(*this);
}