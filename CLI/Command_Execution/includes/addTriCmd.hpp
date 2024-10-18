#include "ICommand.hpp"
#include "../../Parsing/cmdCreator.hpp"

class addTriangle : public ICommand
{
    Command command;
public:
    addTriangle(Command cmd) : command(cmd){}
    void execute() override;
};