#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Document/includes/document.hpp"
#include "../../../Editor/removeShapeAct.hpp"

class removeShape : public ICommand
{    
    int m_slideNumber;            
    std::shared_ptr<Item> m_item; 
public:
    removeShape(int slideNum, std::shared_ptr<Item> item);
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};