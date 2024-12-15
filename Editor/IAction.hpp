#pragma once
#include <memory>

class IAction
{
public:
    virtual std::shared_ptr<IAction> doAction() = 0;
};