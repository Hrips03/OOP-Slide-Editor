#include "ICommand.hpp"
#include "../../Parsing/cmdCreator.hpp"

class help : public ICommand
{
    Command command;
public:
    help(Command cmd) : command(cmd) {}
    void execute() override;
};