#pragma once
#include "../Document/includes/includes.hpp"
#include "../Document/includes/document.hpp"


class Editor
{
    std::shared_ptr<Document> m_doc;

public:
    Editor(std::shared_ptr<Document> document) : m_doc(document) {}

    void addSlide(int pos);
    void remSlide(int pos);

    void addShape(int slideNumber, Shape::ShapeType, Shape::Geometry, Shape::Attributes);    
    void remShape(int slideNumber, Shape::ShapeType, Shape::Geometry, Shape::Attributes);
    
    void printHelp();

    // void printSlide(Command cmd);
    // void printSlides();
};