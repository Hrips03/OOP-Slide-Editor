#include "./includes/addCirCmd.hpp"
#include "../../Editor/editor.hpp"

void addCircle :: execute(){
    auto myDocument = std::make_shared<Document>(); 
    Editor editor(myDocument);
    editor.handler(command);
    std::cout << "Circle is added successfully.\n";
}