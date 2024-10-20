#include "./includes/remTriCmd.hpp"
#include "../../Editor/editor.hpp"

void removeTriangle ::execute()
{
    std::shared_ptr<Document> myDocument = Document::getInstance();
    Editor editor(myDocument);
    editor.handler(command);
    //std::cout << "Removing the triangle.\n";
}