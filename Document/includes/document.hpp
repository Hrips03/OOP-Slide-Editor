#pragma once
#include "includes.hpp"
#include <vector>
#include <iostream>
#include <memory>
#include <map>
#include <variant>

class Document
{
    Document();

    Document(const Document &) = delete;
    Document &operator=(const Document &) = delete;

    Document(const Document &&) = delete;
    Document &&operator=(const Document &&) = delete;

    static std::shared_ptr<Document> instance;

public:
    static std::shared_ptr<Document> getInstance();
    
    //TK: Skhal e
    std::map<Slide, std::vector<std::variant<Circle, Rect, Triangle>>> slides;
    std::vector<Circle> circles;
    std::vector<Rect> rects;
    std::vector<Triangle> triangles;
    std::string help;
};