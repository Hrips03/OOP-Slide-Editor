#include "./includes/remSlideCmd.hpp"
#include "../../Editor/editor.hpp"

void removeSlide ::execute()
{
    auto myDocument = std::make_shared<Document>();
    Editor editor(myDocument);
    editor.handler(command);
    std::cout << "Removing the slide.\n";
}