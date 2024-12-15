#pragma once
#include <memory>
#include <map>
#include <variant>
#include "../../../Editor/IAction.hpp"
#include "../../../Editor/editor.hpp"

class ICommand
{
public:
    virtual void execute() = 0;
    virtual ~ICommand() = default;
    virtual std::shared_ptr<ICommand> clone() const = 0;
};