#include "editor.hpp"

Editor::Editor()
{
    //std::cout << "Instance of Editor is created!\n";
}

std::shared_ptr<Editor> Editor::getInstance()
{
    if (!Editor::instance)
    {
        Editor::instance = std::shared_ptr<Editor>(new Editor());
    }
    return Editor::instance;
}

std::shared_ptr<Editor> Editor::instance = nullptr;

std::shared_ptr<Document> Editor::getDocument(){
    std::shared_ptr<Document> myDocument = Document::getInstance();
    return myDocument;
}

void Editor::process(std::shared_ptr<IAction> act){
    undoStack.push(act->doAction());
    std::stack<std::shared_ptr<IAction>>().swap(redoStack);
}

void Editor::undo(){
    redoStack.push(undoStack.top()->doAction());
    undoStack.pop();
}

void Editor::redo(){
    undoStack.push(redoStack.top()->doAction());
    undoStack.pop();
}