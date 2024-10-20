#include "./includes/addSlideCmd.hpp"
#include "../../Editor/editor.hpp"

void addSlide :: execute(){
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.handler(command);
    //std::cout << "Slide is added successfully.\n";
}