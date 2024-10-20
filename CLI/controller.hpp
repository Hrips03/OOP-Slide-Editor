#pragma once
#include "Parsing/parser.hpp"

class Controller
{
    Parser parser; // composition

public:
    bool m_isRunning = true;
    void run(std::istream &input);
};