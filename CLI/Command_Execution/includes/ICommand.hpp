#pragma once
#include <memory>
#include <map>
#include <variant>

class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void execute() = 0;
    virtual std::unique_ptr<ICommand> clone(std::map<std::string, std::variant<std::string, double>> options) = 0;
};