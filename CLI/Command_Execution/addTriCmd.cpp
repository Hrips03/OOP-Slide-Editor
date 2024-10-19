#include "./includes/addTriCmd.hpp"
#include "../../Editor/editor.hpp"

void addTriangle :: execute(){
    auto myDocument = std::make_shared<Document>(); 
    Editor editor(myDocument);
    editor.handler(command);
    std::cout << "Triangle is added successfully.\n";
}