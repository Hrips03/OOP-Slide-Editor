#include "./includes/addSlideCmd.hpp"
#include "../../Editor/editor.hpp"

void addSlide :: execute(){
    auto myDocument = std::make_shared<Document>(); // Create a shared_ptr for Document
    Editor editor(myDocument);
    editor.handler(command);
    std::cout << "Slide is added successfully.\n";
}