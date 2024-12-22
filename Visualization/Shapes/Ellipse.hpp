#pragma once
#include "IShape.hpp"
#include "../../Document/includes/items.hpp"
#include <iostream>

class Ellipse : public IShape
{
    Item m_item;
    float centerX, centerY, radiusX, radiusY;
public:
    Ellipse(Item item);
    virtual void print(std::ostream& out, size_t shapeIndex) const override;
    void draw() override;
    virtual ~Ellipse() = default;
};