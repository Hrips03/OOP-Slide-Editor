#pragma once
#include <stack>
#include <iostream>
#include "IAction.hpp"
#include "../Document/includes/document.hpp"


class Editor
{
    static std::stack<std::shared_ptr<IAction>> undoStack;
    static std::stack<std::shared_ptr<IAction>> redoStack;
    //std::shared_ptr<Document> doc;
public:
    //std::shared_ptr<Document> getDocument();

    Editor() = default;
    void process(std::shared_ptr<IAction> act);
    void undo();
    void redo();
};
