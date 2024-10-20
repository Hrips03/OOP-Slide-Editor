#include "./includes/addTriCmd.hpp"
#include "../../Editor/editor.hpp"

void addTriangle :: execute(){
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.handler(command);
    //std::cout << "Triangle is added successfully.\n";
}