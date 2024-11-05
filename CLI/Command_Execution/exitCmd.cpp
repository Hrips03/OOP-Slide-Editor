#include "./includes/exitCmd.hpp"

exitCmd::exitCmd(const std::shared_ptr<Controller>& contr) : m_contr(contr) {}

std::shared_ptr<ICommand> exitCmd::clone() const
{
    return std::make_shared<exitCmd>(*this);
}

void exitCmd :: execute(){
    //std::cout << "Executing exit command...\n";
    m_contr->exit();
}