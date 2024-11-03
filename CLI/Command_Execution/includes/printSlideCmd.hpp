#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Editor/editor.hpp"

class printSlide : public ICommand
{
    int m_position;
public:
    printSlide(int pos);
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};