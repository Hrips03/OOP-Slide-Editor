#pragma once
#include "includes.hpp"
#include <vector>
#include <iostream>
#include <memory>
#include "../../Visualization/visualizer.hpp"

class Document
{
public:
    Document() = default;
    static std::vector<std::shared_ptr<Slide>> slides;

    void addSlide(std::shared_ptr<Slide> slide);
    void remSlide(int pos);

    void addShape(int slideNumber, std::shared_ptr<Item>);
    void remShape(int slideNumber, int itemNumber);

    void printHelp();

    void printSlide(int pos);
    void printSlides();
};