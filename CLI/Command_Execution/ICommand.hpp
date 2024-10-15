#include "includes.hpp"
#include "Input_Manipulation/cmdCreator.hpp"

class ICommand
{
    std::shared_ptr<CommandCreator> command;     // agregation
public:
    virtual void execute() = 0;
};