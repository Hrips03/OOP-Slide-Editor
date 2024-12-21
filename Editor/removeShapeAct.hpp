#pragma once
#include "IAction.hpp"
#include "../Document/includes/slide.hpp"
#include "../Document/includes/document.hpp"
#include "addShapeAction.hpp"

class removeShapeAct : public IAction
{
    int m_slideID;
    std::shared_ptr<Item> m_item;
public:
    removeShapeAct(int slide, std::shared_ptr<Item> item);
    std::shared_ptr<IAction> doAction() override;
    virtual ~removeShapeAct() = default;
};