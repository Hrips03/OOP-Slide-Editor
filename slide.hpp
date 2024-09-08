#pragma once
#include <iostream>
#include <cassert>
#include <map>

class Slide
{
    size_t slidesCount = 0;

public:
    void add(int pos = 0);
    void remove(size_t pos);
};