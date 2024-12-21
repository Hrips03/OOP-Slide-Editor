#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Document/includes/document.hpp"
#include "../../../Editor/removeShapeAct.hpp"

class removeShape : public ICommand
{    
    int m_slideNumber;            
    int m_itemNum; 
public:
    removeShape(int slideNum, int itemNum);
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};