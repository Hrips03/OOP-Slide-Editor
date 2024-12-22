#pragma once
#include "IAction.hpp"
#include "../Document/includes/document.hpp"
#include "addSlideAction.hpp"

class removeSlideAct : public IAction
{
    int m_pos;
    std::shared_ptr<Document> m_doc = nullptr;
public:
    removeSlideAct(int pos);
    std::shared_ptr<IAction> doAction() override;
    virtual ~removeSlideAct() = default;
};