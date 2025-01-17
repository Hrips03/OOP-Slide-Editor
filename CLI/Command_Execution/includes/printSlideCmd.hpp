#pragma once
#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Document/includes/document.hpp"

class printSlide : public ICommand
{
    int m_position;
    std::shared_ptr<Document> m_doc = nullptr;
public:
    printSlide(int pos);
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};