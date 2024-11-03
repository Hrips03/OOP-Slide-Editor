#pragma once
#include <memory>
#include <map>
#include <variant>

class ICommand
{
public:
    virtual void execute() = 0;
    virtual ~ICommand() = default;
    virtual std::shared_ptr<ICommand> clone() const = 0;
};