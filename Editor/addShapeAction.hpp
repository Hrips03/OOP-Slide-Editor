#pragma once
#include "IAction.hpp"
#include "../Document/includes/slide.hpp"
#include "../Document/includes/document.hpp"
#include "removeShapeAct.hpp"
#include <algorithm>

class addShapeAct : public IAction
{
    int m_slideID;
    std::shared_ptr<Item> m_item;
public:
    addShapeAct(int slide, std::shared_ptr<Item> item);
    std::shared_ptr<IAction> doAction() override;
    virtual ~addShapeAct() = default;
};