#include "./includes/addCirCmd.hpp"
#include "../../Editor/editor.hpp"

void addCircle :: execute(){
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.handler(command);
    //std::cout << "Circle is added successfully.\n";
}