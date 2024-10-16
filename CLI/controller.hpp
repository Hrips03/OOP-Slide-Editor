#pragma once
#include "Input_Manipulation/parser.hpp"

class Controller
{
    Parser parser;  //composition
    bool m_isRunning; 
    
public:
    void run(std::istream &input);
};