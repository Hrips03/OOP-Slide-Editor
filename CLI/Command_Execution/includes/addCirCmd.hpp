#include "ICommand.hpp"
#include "../../Parsing/cmdCreator.hpp"
#include "../../../Editor/editor.hpp"

class addCircle : public ICommand
{
    Command command;
    std::shared_ptr<Editor> editor;
public:
    addCircle(Command cmd) : command(cmd){}
    void execute() override;
};