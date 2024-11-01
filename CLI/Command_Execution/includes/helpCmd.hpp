#include "ICommand.hpp"
#include <vector>
#include <iostream>

class help : public ICommand
{
    std::vector<std::string> arguments;

public:
    help(const std::vector<std::string> &args);
    void execute() override;
    std::unique_ptr<ICommand> clone() const override;
};