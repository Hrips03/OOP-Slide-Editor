#pragma once
#include <sstream>
#include <map>
#include "../Document/includes/document.hpp"

class Visualizer
{
public:
    void printSlide(std::ostream &outputStream, std::vector<Slide>::iterator slideIt);
};