#include "./includes/remSlideCmd.hpp"

// void removeSlide ::execute()
// {
//     std::shared_ptr<Document> myDocument = Document::getInstance();
//     Editor editor(myDocument);
//     editor.handler(command);
//     //std::cout << "Removing the slide.\n";
// }

removeSlide::removeSlide(const std::vector<std::string> &args) : arguments(args) {}

std::unique_ptr<ICommand> removeSlide::clone() const
{
    return std::make_unique<removeSlide>(*this);
}