#include "ICommand.hpp"

class exit : public ICommand
{
public:
    void execute() override;
};