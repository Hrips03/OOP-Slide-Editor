#pragma once
#include "IAction.hpp"
#include "../Document/includes/slide.hpp"
#include "../Document/includes/document.hpp"
#include "addShapeAction.hpp"

class removeShapeAct : public IAction
{
    int m_slideID;
    int m_itemID;
public:
    removeShapeAct(int slideNum, int itemNum);
    std::shared_ptr<IAction> doAction() override;
    virtual ~removeShapeAct() = default;
};