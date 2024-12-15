#pragma once
#include "IAction.hpp"
#include "../Document/includes/slide.hpp"

class changeGeom : public IAction
{
    Slide sId;
    Item iId;

public:
    std::shared_ptr<IAction> doAction() override;
};
