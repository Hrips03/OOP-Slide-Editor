#pragma once
#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Editor/editor.hpp"

class RedoCmd : public ICommand
{
    std::shared_ptr<Editor> m_editor = nullptr;

public:
    RedoCmd();
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};