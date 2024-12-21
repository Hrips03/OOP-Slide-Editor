#pragma once
#include "items.hpp"
#include <vector>

class Slide
{
    int m_pos;

public:
    Slide(int position);
    int getPosition() const;
    void setPosition(int pos);
    std::vector<Item> items;
};