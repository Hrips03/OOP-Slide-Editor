#include "./includes/remSlideCmd.hpp"
#include "../../Editor/editor.hpp"

void removeSlide ::execute()
{
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.handler(command);
    //std::cout << "Removing the slide.\n";
}