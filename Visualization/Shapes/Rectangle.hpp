#pragma once
#include "IShape.hpp"
#include "../../Document/includes/items.hpp"
#include <iostream>

class Rectangle : public IShape
{
    Item m_item;
public:
    Rectangle(Item item);
    virtual void print(std::ostream& out, size_t shapeIndex) const override;
    void draw() override;
    virtual ~Rectangle() = default;
};