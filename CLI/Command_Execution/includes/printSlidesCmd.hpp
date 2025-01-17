#pragma once
#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Document/includes/document.hpp"

class printSlides : public ICommand
{
    std::shared_ptr<Document> m_doc = nullptr;
public:
    printSlides();
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};