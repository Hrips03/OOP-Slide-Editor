#include "ICommand.hpp"
#include "../../Parsing/cmdCreator.hpp"

class addCircle : public ICommand
{
    Command command;
public:
    addCircle(Command cmd) : command(cmd){}
    void execute() override;
};