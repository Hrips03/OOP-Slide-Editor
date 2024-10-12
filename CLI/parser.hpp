#pragma once
#include "syntaxAnalyzer.hpp"


class Parser
{
    SyntaxAnalyzer syntaxAnalyzer;   // compostion
    LexicalAnalyzer lexicalAnalyzer; // compostion
    
    int position = 0;
    
public:
    void parse(std::string input);
};