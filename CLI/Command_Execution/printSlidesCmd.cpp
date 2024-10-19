#include "./includes/printSlidesCmd.hpp"
#include "../../Editor/editor.hpp"

void printSlides ::execute()
{
    auto myDocument = std::make_shared<Document>();
    Editor editor(myDocument);
    editor.handler(command);
    std::cout << "Printing all slides.\n";
}