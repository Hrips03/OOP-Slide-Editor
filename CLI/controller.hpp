#pragma once
#include "parser.hpp"

class Controller
{
    Parser parser;  //composition
    std::string input;
public:
    void getCommand();
    void parse();
};