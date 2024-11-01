#include "ICommand.hpp"
#include <vector>
#include <iostream>

class printSlide : public ICommand
{
public:
    std::vector<std::string> arguments;

public:
    printSlide(const std::vector<std::string> &args);
    void execute() override;
    std::unique_ptr<ICommand> clone() const override;
};