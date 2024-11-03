#include "./includes/helpCmd.hpp"

std::shared_ptr<ICommand> help::clone() const
{
    return std::make_shared<help>(*this);
}

void help :: execute(){
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.printHelp();
}