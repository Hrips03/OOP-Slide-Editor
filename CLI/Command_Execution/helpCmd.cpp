#include "./includes/helpCmd.hpp"
#include "../../Editor/editor.hpp"

void help :: execute(){
    auto myDocument = std::make_shared<Document>(); 
    Editor editor(myDocument);
    editor.handler(command);
    std::cout << "Printing help.\n";
}