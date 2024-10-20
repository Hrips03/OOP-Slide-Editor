#pragma once
#include <sstream>
#include <map>
#include "../Document/includes/document.hpp"

class Visualizer
{
public:
    void printSlide(std::ostream &outputStream, std::map<Slide, std::vector<std::variant<Circle, Rect, Triangle>>>::iterator slideIt);
    void printSlides(std::ostream &outputStream, std::map<Slide, std::vector<std::variant<Circle, Rect, Triangle>>> slides);
};