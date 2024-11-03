#pragma once
#include "includes.hpp"
#include <vector>
#include <iostream>
#include <memory>
#include <map>
#include <variant>

class Document
{
    Document();

    Document(const Document &) = delete;
    Document &operator=(const Document &) = delete;

    Document(const Document &&) = delete;
    Document &&operator=(const Document &&) = delete;

    static std::shared_ptr<Document> instance;

public:
    std::vector<Slide> slides;
    static std::shared_ptr<Document> getInstance();
};