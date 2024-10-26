#pragma once
#include "Parsing/parser.hpp"

class Controller
{
    bool m_isRunning = true;
public:
    void run(std::istream &input);
    void exit();
};