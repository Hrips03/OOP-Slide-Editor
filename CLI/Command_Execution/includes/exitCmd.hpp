#include "ICommand.hpp"
#include <vector>
#include <iostream>

class exit : public ICommand
{
    std::vector<std::string> arguments;

public:
    exit(const std::vector<std::string> &args);
    void execute() override;
    std::unique_ptr<ICommand> clone() const override;
};