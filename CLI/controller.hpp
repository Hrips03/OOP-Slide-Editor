#pragma once
#include "Parsing/parser.hpp"

class Controller
{
    Parser parser; // composition, unused member, delete

public:
    bool m_isRunning = true; //TK: This is bad, members should not be public, you should have a method exit()
    void run(std::istream &input);
};
