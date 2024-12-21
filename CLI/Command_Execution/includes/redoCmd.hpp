#pragma once
#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Editor/editor.hpp"

class RedoCmd : public ICommand
{
public:
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};