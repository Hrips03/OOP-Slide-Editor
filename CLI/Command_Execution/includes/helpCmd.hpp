#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Document/includes/document.hpp"

class help : public ICommand
{
    std::shared_ptr<Document> m_doc = nullptr;
public:
    help();
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};