#include "./includes/remTriCmd.hpp"
#include "../../Editor/editor.hpp"

void removeTriangle ::execute()
{
    auto myDocument = std::make_shared<Document>();
    Editor editor(myDocument);
    editor.handler(command);
    std::cout << "Removing the triangle.\n";
}