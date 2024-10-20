#include "editor.hpp"
#include "function_imp.hpp"

void Editor::handler(Command cmd)
{
    if (cmd.cmdName == "add slide")
        addSlide(cmd);
    else if (cmd.cmdName == "add circle")
        addCircle(cmd);
    else if (cmd.cmdName == "add rect")
        addRect(cmd);
    else if (cmd.cmdName == "add triangle")
        addTriangle(cmd);
    else if (cmd.cmdName == "remove slide")
        remSlide(cmd);
    else if (cmd.cmdName == "remove circle")
        remCircle(cmd);
    else if (cmd.cmdName == "remove rect")
        remRect(cmd);
    else if (cmd.cmdName == "remove triangle")
        remTriangle(cmd);
    else if (cmd.cmdName == "print slide")
        printSlide(cmd);
    else if (cmd.cmdName == "print slides")
        printSlides();
    else if (cmd.cmdName == "help")
        printHelp();
}