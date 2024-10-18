#include "ICommand.hpp"
#include "../../Parsing/cmdCreator.hpp"

class addRectangle : public ICommand
{
    Command command;
public:
    addRectangle(Command cmd) : command(cmd){}
    void execute() override;
};