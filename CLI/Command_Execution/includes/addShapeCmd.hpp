#pragma once
#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Editor/addShapeAction.hpp"

class addShape : public ICommand
{
    int m_slideNumber; 
    std::shared_ptr<Item> m_item;
    std::shared_ptr<Editor> m_editor = nullptr;
public:
    addShape(int slideNum, std::shared_ptr<Item> item);
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};