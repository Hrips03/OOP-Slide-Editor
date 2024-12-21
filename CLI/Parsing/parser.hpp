#pragma once
#include "syntaxAnalyzer.hpp"
#include "cmdCreator.hpp"
#include <limits>

class Parser
{
    SyntaxAnalyzer syntaxAnalyzer;   
    LexicalAnalyzer lexicalAnalyzer;
public:
    std::shared_ptr<ICommand> parse(std::istream &inputStream);
};