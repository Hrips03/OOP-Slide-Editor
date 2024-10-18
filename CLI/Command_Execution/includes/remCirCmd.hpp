#include "ICommand.hpp"
#include "../../Parsing/cmdCreator.hpp"

class removeCircle : public ICommand
{
    Command command;
public:
    removeCircle(Command cmd) : command(cmd){}
    void execute() override;
};