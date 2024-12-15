#pragma once
#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Document/includes/document.hpp"
#include "../../controller.hpp"

class Controller;

class exitCmd : public ICommand
{
    std::shared_ptr<Controller> m_contr;
public:
    exitCmd() = default;
    exitCmd(const std::shared_ptr<Controller>& contr);
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};