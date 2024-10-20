#include "./includes/printSlidesCmd.hpp"
#include "../../Editor/editor.hpp"

void printSlides ::execute()
{
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.handler(command);
    //std::cout << "Printing all slides.\n";
}