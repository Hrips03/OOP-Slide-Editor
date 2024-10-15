#include "ICommand.hpp"

class removeShape : public ICommand
{
public:
    void execute() override;
};