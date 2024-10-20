#include "./includes/addRectCmd.hpp"
#include "../../Editor/editor.hpp"

void addRectangle :: execute(){
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.handler(command);
    //std::cout << "Rectangle is added successfully.\n";
}