#include "includes/document.hpp"

Document::Document()
{
    std::cout << "Instance of Document is created!\n";
}

std::shared_ptr<Document> Document::getInstance()
{
    if (!Document::instance)
    {
        Document::instance = std::shared_ptr<Document>(new Document());
    }
    return Document::instance;
}

std::shared_ptr<Document> Document::instance = nullptr;