#include "ICommand.hpp"
#include "../../Parsing/cmdCreator.hpp"

class printSlides : public ICommand
{
    Command command;
public:
    printSlides(Command cmd) : command(cmd) {}
    void execute() override;
};