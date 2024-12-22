#pragma once
#include "includes.hpp"
#include <vector>
#include <iostream>
#include <memory>
#include "../../Visualization/visualizer.hpp"
#include <fstream>
#include <filesystem>
#include <sstream>
#include <algorithm>  // For std::replace
#include <string>     // For std::string
#include <sstream>    // For std::istringstream
#include "../../Visualization/Shapes/IShape.hpp"
#include "../../Visualization/Shapes/Ellipse.hpp"
#include "../../Visualization/Shapes/Rectangle.hpp"
#include "../../Visualization/Shapes/Triangle.hpp"

class Document
{
public:
    Document() = default;
    static std::vector<std::shared_ptr<Slide>> slides;

    void addSlide(std::shared_ptr<Slide> slide);
    void remSlide(int pos);

    void addShape(int slideNumber, std::shared_ptr<Item>);
    void remShape(int slideNumber, int itemNumber);

    void changeGeom(int slideNum, int itemNum, Item::Geometry itemGeom, Item::Attributes itemAttribs);

    void save(const std::string& fileName);
    void load(const std::string& fileName);
    std::shared_ptr<IShape> createShapeFromItem(const Item& item);

    void printHelp();

    void printSlide(int pos);
    void printSlides();
};