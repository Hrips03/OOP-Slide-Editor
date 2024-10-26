#pragma once
#include "includes.hpp"
#include <vector>
#include <iostream>
#include <memory>
#include <map>
#include <variant>

class Document
{
public:
    std::vector<Slide> slides;
};