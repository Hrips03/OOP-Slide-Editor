#include "./includes/remRectCmd.hpp"
#include "../../Editor/editor.hpp"

void removeRectangle ::execute()
{
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.handler(command);
    //std::cout << "Removing the rectangle.\n";
}