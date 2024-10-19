#include "./includes/printSlideCmd.hpp"
#include "../../Editor/editor.hpp"

void printSlide :: execute(){
    auto myDocument = std::make_shared<Document>(); 
    Editor editor(myDocument);
    editor.handler(command);
    std::cout << "Printing the slide.\n";
}