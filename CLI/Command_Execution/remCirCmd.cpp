#include "./includes/remCirCmd.hpp"
#include "../../Editor/editor.hpp"

void removeCircle ::execute()
{
    auto myDocument = std::make_shared<Document>();
    Editor editor(myDocument);
    editor.handler(command);
    std::cout << "Removing the circle.\n";
}