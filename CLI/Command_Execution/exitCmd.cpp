#include "./includes/exitCmd.hpp"
#include "../../Editor/editor.hpp"

void exitCmd :: execute(){
    auto myDocument = std::make_shared<Document>(); 
    Editor editor(myDocument);
    editor.handler(command);
    std::cout << "Exiting the programm.\n";
}