#include "ICommand.hpp"

class printSlide : public ICommand
{
public:
    void execute() override;
};