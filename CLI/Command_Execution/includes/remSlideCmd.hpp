#include "ICommand.hpp"
#include <vector>
#include <iostream>

class removeSlide : public ICommand
{
public:
    std::vector<std::string> arguments;

public:
    removeSlide(const std::vector<std::string> &args);
    void execute() override;
    std::unique_ptr<ICommand> clone() const override;
};
