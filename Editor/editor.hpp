#pragma once
#include "../CLI/Parsing/cmdCreator.hpp"
#include "../Document/includes/includes.hpp"
#include "../Document/includes/document.hpp"

class Editor
{
    std::shared_ptr<Document> doc;

public:
    Editor(std::shared_ptr<Document> document) : doc(document) {}
    void handler(Command cmd);
};