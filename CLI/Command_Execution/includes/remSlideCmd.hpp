#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Document/includes/document.hpp"
#include "../../../Editor/removeSlideAct.hpp"

class removeSlide : public ICommand
{
    int m_position;
public:
    removeSlide(int pos);
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};
