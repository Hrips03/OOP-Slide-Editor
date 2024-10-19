#include "./includes/addRectCmd.hpp"
#include "../../Editor/editor.hpp"

void addRectangle :: execute(){
    auto myDocument = std::make_shared<Document>(); 
    Editor editor(myDocument);
    editor.handler(command);
    std::cout << "Rectangle is added successfully.\n";
}