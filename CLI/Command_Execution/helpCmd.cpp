#include "./includes/helpCmd.hpp"
#include "../../Application.hpp"

help::help(){
    //m_doc = std::shared_ptr<Document>(new Document());
    m_doc = Application::getInstance()->getDocument();
}

std::shared_ptr<ICommand> help::clone() const
{
    return std::make_shared<help>(*this);
}

void help :: execute(){
    m_doc->printHelp();
}