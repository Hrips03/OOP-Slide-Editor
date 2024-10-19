#pragma once
#include "includes.hpp"
#include <vector>

class Document
{
public:
    std::vector<Slide> slides;
    std::vector<Circle> circles;
    std::vector<Rect> rects;
    std::vector<Triangle> triangles;
    std::string help;
};