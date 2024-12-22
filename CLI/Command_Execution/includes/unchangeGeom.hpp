#include "ICommand.hpp"
#include <vector>
#include <iostream>
#include "../../../Document/includes/document.hpp"
#include "../../../Editor/changeGeomAct.hpp"

class unchangeGeometry : public ICommand
{
    int m_slideNumber; 
    int m_itemNum;
    Item::Geometry m_itemGeom;
    Item::Attributes m_itemAttribs;
    std::shared_ptr<Editor> m_editor = nullptr;
public:
    unchangeGeometry(int slideNum, int itemNum, Item::Geometry itemGeom, Item::Attributes itemAttribs);
    void execute() override;
    std::shared_ptr<ICommand> clone() const override;
};