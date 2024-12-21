#pragma once
#include <sstream>
#include <map>
#include "../Document/includes/document.hpp"

class Visualizer
{
public:
    void printSlide(std::ostream &out, std::shared_ptr<Slide> slide, size_t slideIndex);
    void printSlides(std::ostream &out, const std::vector<std::shared_ptr<Slide>>& slides);
};