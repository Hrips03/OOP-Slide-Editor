#include "ICommand.hpp"
#include "../../../Editor/editor.hpp"
#include <vector>
#include <iostream>

class addSlide : public ICommand
{
    int m_position; 
public:
    addSlide(int pos);
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};