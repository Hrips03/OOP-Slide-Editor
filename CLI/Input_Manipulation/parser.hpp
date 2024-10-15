#pragma once
#include "syntaxAnalyzer.hpp"
#include "cmdCreator.hpp"


class Parser
{
    SyntaxAnalyzer syntaxAnalyzer;   // compostion
    LexicalAnalyzer lexicalAnalyzer; // compostion

    std::weak_ptr<CommandCreator> command; //association

    int position = 0;
    
public:
    void parse(std::string input);
};