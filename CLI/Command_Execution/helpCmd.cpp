#include "./includes/helpCmd.hpp"

help::help(){
    std::shared_ptr<Document> m_doc = std::shared_ptr<Document>(new Document());
}

std::shared_ptr<ICommand> help::clone() const
{
    return std::make_shared<help>(*this);
}

void help :: execute(){
    m_doc->printHelp();
}