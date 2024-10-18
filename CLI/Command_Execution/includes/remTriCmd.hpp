#include "ICommand.hpp"
#include "../../Parsing/cmdCreator.hpp"

class removeTriangle : public ICommand
{
    Command command;
public:
    removeTriangle(Command cmd) : command(cmd){}
    void execute() override;
};