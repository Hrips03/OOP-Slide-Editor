#pragma once
#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Editor/addSlideAction.hpp"

class addSlide : public ICommand
{
    int m_position; 
    std::shared_ptr<Editor> m_editor = nullptr;
public:
    addSlide(int pos);
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};