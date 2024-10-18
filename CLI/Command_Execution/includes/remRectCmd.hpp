#include "ICommand.hpp"
#include "../../Parsing/cmdCreator.hpp"

class removeRectangle : public ICommand
{
    Command command;
public:
    removeRectangle(Command cmd) : command(cmd){}
    void execute() override;
};