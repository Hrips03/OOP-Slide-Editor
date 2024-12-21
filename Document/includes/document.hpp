#pragma once
#include "includes.hpp"
#include <vector>
#include <iostream>
#include <memory>
#include "../../Visualization/visualizer.hpp"


class Document
{
    Document();

    Document(const Document &) = delete;
    Document &operator=(const Document &) = delete;

    Document(const Document &&) = delete;
    Document &&operator=(const Document &&) = delete;

    static std::shared_ptr<Document> instance;

public:
    std::vector<Slide> slides;
    static std::shared_ptr<Document> getInstance();

    void addSlide(int pos);
    void remSlide(int pos);

    void addShape(int slideNumber, std::shared_ptr<Item>);    
    void remShape(int slideNumber, std::shared_ptr<Item>);
    
    void printHelp();

    void printSlide(int pos);
    void printSlides();

};