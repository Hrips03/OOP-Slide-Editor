#include "ICommand.hpp"

class help : public ICommand
{
public:
    void execute() override;
};