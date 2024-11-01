#include "ICommand.hpp"
#include <vector>
#include <iostream>

class addSlide : public ICommand
{
public:
    std::vector<std::string> arguments;

public:
    addSlide(const std::vector<std::string> &args);
    void execute() override;
    std::unique_ptr<ICommand> clone() const override;
};