#pragma once
#include "./Parsing/cmdCreator.hpp"
#include "./Command_Execution/includes/ICommand.hpp"
#include "./Command_Execution/includes/addSlideCmd.hpp"

class CommandAdapter : public ICommand
{
    Command command;
public:
    CommandAdapter(const Command &cmd) : command(cmd) {}    
    
    //where should I do this?
    void execute() override {
        if (command.cmdName == "add slide") {
            // addSlide addSlideCommand(command);
            // addSlideCommand.execute();
        } else if (command.cmdName == "remove slide") {
            // Implement remove slide logic
            std::cout << "Removing slide at position: "
                      << std::get<double>(command.argList.at("pos")) << std::endl;
        } 
        // Add additional else if statements for other commands like AddRect, RemoveRect, etc.
    }
};