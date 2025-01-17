#pragma once
#include <memory>
// #include "../Application.hpp"

class IAction
{
public:
    virtual std::shared_ptr<IAction> doAction() = 0;
};