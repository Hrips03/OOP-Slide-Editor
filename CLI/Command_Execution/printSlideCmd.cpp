#include "./includes/printSlideCmd.hpp"

// void printSlide :: execute(){
//     std::shared_ptr<Document> myDocument = Document::getInstance();
//     Editor editor(myDocument);
//     editor.handler(command);
//     //std::cout << "Printing the slide.\n";
// }

printSlide::printSlide(const std::vector<std::string> &args) : arguments(args) {}

std::unique_ptr<ICommand> printSlide::clone() const
{
    return std::make_unique<printSlide>(*this);
}