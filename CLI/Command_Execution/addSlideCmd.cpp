#include "./includes/addSlideCmd.hpp"

// void addSlide :: execute(){
//     std::shared_ptr<Document> myDocument = Document::getInstance();
//     m_pEditor->addSliude(m_nPosition);
//     //std::cout << "Slide is added successfully.\n";
// }

std::unique_ptr<ICommand> addSlide::clone(std::map<std::string, std::variant<std::string, double>> options) {
        return std::make_unique<addSlide>(options);
    }