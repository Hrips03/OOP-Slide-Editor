#include "./includes/redoCmd.hpp"

void RedoCmd ::execute()
{
    Editor::getInstance()->redo();
}

std::shared_ptr<ICommand> RedoCmd::clone() const
{
    return std::make_shared<RedoCmd>(*this);
}