#pragma once
#include "IAction.hpp"
#include "../Document/includes/slide.hpp"
#include "../Document/includes/document.hpp"
#include "unchangeGeomAct.hpp"

class changeGeometryAct : public IAction
{
    int m_slideNumber;
    int m_itemNum;
    Item::Geometry m_itemGeom;
    Item::Attributes m_itemAttribs;
    std::shared_ptr<Document> m_doc = nullptr;
public:
    changeGeometryAct(int slideNum, int itemNum, Item::Geometry itemGeom, Item::Attributes itemAttribs);
    std::shared_ptr<IAction> doAction() override;
    virtual ~changeGeometryAct() = default;
};