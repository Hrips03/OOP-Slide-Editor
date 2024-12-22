#pragma once
#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Document/includes/document.hpp"

class loadCmd : public ICommand
{
    std::string m_fileName;
    std::shared_ptr<Document> m_doc = nullptr;
public:
    loadCmd(std::string fileName);
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};