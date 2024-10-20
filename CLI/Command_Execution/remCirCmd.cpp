#include "./includes/remCirCmd.hpp"
#include "../../Editor/editor.hpp"

void removeCircle ::execute()
{
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.handler(command);
    //std::cout << "Removing the circle.\n";
}