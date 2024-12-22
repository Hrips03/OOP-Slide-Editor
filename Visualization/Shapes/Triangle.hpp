#pragma once
#include "IShape.hpp"
#include "../../Document/includes/items.hpp"
#include <iostream>
#include <cmath>

class Triangle : public IShape
{
    Item m_item;
public:
    Triangle(Item item);
    virtual void print(std::ostream& out, size_t shapeIndex) const override;
    void draw() override;
    virtual ~Triangle() = default;
};