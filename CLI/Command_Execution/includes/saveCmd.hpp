#pragma once
#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Document/includes/document.hpp"

class saveCmd : public ICommand
{
    std::string m_fileName;
    std::shared_ptr<Document> m_doc = nullptr;
public:
    saveCmd(std::string fileName);
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};