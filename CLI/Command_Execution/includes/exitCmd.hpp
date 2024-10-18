#include "ICommand.hpp"
#include "../../Parsing/cmdCreator.hpp"

class exitCmd : public ICommand
{
    Command command;
public:
    exitCmd(Command cmd) : command(cmd) {}
    void execute() override;
};