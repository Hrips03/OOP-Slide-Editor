#pragma once
#include "../CLI/Parsing/cmdCreator.hpp"
#include "../Document/includes/includes.hpp"
#include "../Document/includes/document.hpp"
#include "../Visualization/visualizer.hpp"

class Editor
{
    std::shared_ptr<Document> doc;

public:
    Editor(std::shared_ptr<Document> document) : doc(document) {}
    void handler(Command cmd);

    void addSlide(Command cmd);
    void addCircle(Command cmd);
    void addRect(Command cmd);
    void addTriangle(Command cmd);

    void remSlide(Command cmd);
    void remCircle(Command cmd);
    void remRect(Command cmd);
    void remTriangle(Command cmd);

    void printHelp();
    void printSlide(Command cmd);
    void printSlides();
};