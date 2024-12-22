#include "editor.hpp"

std::stack<std::shared_ptr<IAction>> Editor::undoStack;
std::stack<std::shared_ptr<IAction>> Editor::redoStack;

// std::shared_ptr<Document> Editor::getDocument(){
//     std::shared_ptr<Document> myDocument = Document::getInstance();
//     return myDocument;
// }

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
    //undoStack.pop();
    redoStack.pop();
}