#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Editor/editor.hpp"

class help : public ICommand
{
public:
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};