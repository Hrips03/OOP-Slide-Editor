#include "ICommand.hpp"
#include "../../Parsing/cmdCreator.hpp"

class removeSlide : public ICommand
{
    Command command;
public:
    removeSlide(Command cmd) : command(cmd) {}
    void execute() override;
};

