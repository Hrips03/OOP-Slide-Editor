#pragma once
#include <stack>
#include <iostream>
#include "IAction.hpp"
#include "../Document/includes/document.hpp"

class Editor
{
    Editor();

    Editor(const Editor &) = delete;
    Editor &operator=(const Editor &) = delete;

    Editor(const Editor &&) = delete;
    Editor &&operator=(const Editor &&) = delete;

    static std::shared_ptr<Editor> instance;

    std::stack<std::shared_ptr<IAction>> undoStack;
    std::stack<std::shared_ptr<IAction>> redoStack;
    std::shared_ptr<Document> doc;

public:
    static std::shared_ptr<Editor> getInstance();
    std::shared_ptr<Document> getDocument();

    void process(std::shared_ptr<IAction> act);
    void undo();
    void redo();
};
