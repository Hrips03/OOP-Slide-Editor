#include "./includes/remRectCmd.hpp"
#include "../../Editor/editor.hpp"

void removeRectangle ::execute()
{
    auto myDocument = std::make_shared<Document>();
    Editor editor(myDocument);
    editor.handler(command);
    std::cout << "Removing the rectangle.\n";
}