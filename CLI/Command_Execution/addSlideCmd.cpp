#include "./includes/addSlideCmd.hpp"

// void addSlide :: execute(){
//     std::shared_ptr<Document> myDocument = Document::getInstance();
//     m_pEditor->addSliude(m_nPosition);
//     //std::cout << "Slide is added successfully.\n";
// }

addSlide::addSlide(const std::vector<std::string> &args) : arguments(args) {}

std::unique_ptr<ICommand> addSlide::clone() const
{
    return std::make_unique<addSlide>(*this);
}