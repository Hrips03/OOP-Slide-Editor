#include "./includes/redoCmd.hpp"

RedoCmd::RedoCmd(){
    std::shared_ptr<Editor> m_editor = std::shared_ptr<Editor>(new Editor());
}

void RedoCmd ::execute()
{
    m_editor->redo();
}

std::shared_ptr<ICommand> RedoCmd::clone() const
{
    return std::make_shared<RedoCmd>(*this);
}