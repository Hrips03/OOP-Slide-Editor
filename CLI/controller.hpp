#pragma once
#include "Parsing/parser.hpp"

class Controller
{
    Parser parser; // composition
    bool m_isRunning;
public:
   
    void run(std::istream &input);
};