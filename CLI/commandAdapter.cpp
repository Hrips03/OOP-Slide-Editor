#include "commandAdapter.hpp"

void CommandAdapter::execute() 
{
    if (command.cmdName == "add slide")
    {
        addSlide addSlideCommand(command);
        addSlideCommand.execute();
    }
    else if (command.cmdName == "remove slide")
    {
        removeSlide removeSlideCommand(command);
        removeSlideCommand.execute();
    }
    else if (command.cmdName == "print slide")
    {
        printSlide printSlideCommand(command);
        printSlideCommand.execute();
    }
    if (command.cmdName == "add circle")
    {
        addCircle addCircleCommand(command);
        addCircleCommand.execute();
    }
    else if (command.cmdName == "remove circle")
    {
        removeCircle removeCircleCommand(command);
        removeCircleCommand.execute();
    }
    if (command.cmdName == "add rect")
    {
        addRectangle addRectCommand(command);
        addRectCommand.execute();
    }
    else if (command.cmdName == "remove rect")
    {
        removeRectangle removeRectCommand(command);
        removeRectCommand.execute();
    }
    if (command.cmdName == "add triangle")
    {
        addTriangle addTriangleCommand(command);
        addTriangleCommand.execute();
    }
    else if (command.cmdName == "remove triangle")
    {
        removeTriangle removeTriangleCommand(command);
        removeTriangleCommand.execute();
    }
    else if (command.cmdName == "print slides")
    {
        printSlides printSlidesCommand(command);
        printSlidesCommand.execute();
    }
    else if (command.cmdName == "help")
    {
        help helpCommand(command);
        helpCommand.execute();
    }
}
