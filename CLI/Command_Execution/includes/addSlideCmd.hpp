#include "ICommand.hpp"
#include "../../Parsing/cmdCreator.hpp"

class addSlide : public ICommand
{
    Command command;
public:
    addSlide(Command cmd) : command(cmd){}
    void execute() override;
};