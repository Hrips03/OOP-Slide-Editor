#pragma once
#include "IAction.hpp"
#include "../Document/includes/slide.hpp"
#include "../Document/includes/document.hpp"
#include "removeSlideAct.hpp"

class addSlideAct : public IAction
{
    std::shared_ptr<Slide> m_slide;
    int m_pos;
public:
    addSlideAct(std::shared_ptr<Slide> newSlide, int pos);
    std::shared_ptr<IAction> doAction() override;
    virtual ~addSlideAct() = default;
};