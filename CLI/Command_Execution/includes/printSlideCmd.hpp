#include "ICommand.hpp"
#include "../../Parsing/cmdCreator.hpp"

class printSlide : public ICommand
{
    Command command;
public:
    printSlide(Command cmd) : command(cmd) {}
    void execute() override;
};