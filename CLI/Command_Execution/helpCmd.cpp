#include "./includes/helpCmd.hpp"
#include "../../Editor/editor.hpp"

void help :: execute(){
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.handler(command);
    //std::cout << "Printing help.\n";
}