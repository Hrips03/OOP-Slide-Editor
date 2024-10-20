#include "./includes/printSlideCmd.hpp"
#include "../../Editor/editor.hpp"

void printSlide :: execute(){
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.handler(command);
    //std::cout << "Printing the slide.\n";
}