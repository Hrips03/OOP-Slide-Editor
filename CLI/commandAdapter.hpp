#pragma once
#include "./Parsing/cmdCreator.hpp"
#include "./Command_Execution/includes/commands.hpp"

class CommandAdapter : public ICommand
{
    Command command;
public:
    CommandAdapter(const Command &cmd) : command(cmd) {}
    void execute() override;
};