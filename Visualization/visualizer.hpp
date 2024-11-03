#pragma once
#include <sstream>
#include <map>
#include "../Document/includes/document.hpp"

class Visualizer
{
public:
    void printSlide(std::ostream &out, std::vector<Slide>::iterator slideIt, size_t slideIndex);
    void printSlides(std::ostream &out, std::vector<Slide> &slides);
};