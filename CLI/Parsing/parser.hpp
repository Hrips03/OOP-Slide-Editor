#pragma once
#include "syntaxAnalyzer.hpp"
#include "cmdCreator.hpp"


class Parser
{
    SyntaxAnalyzer syntaxAnalyzer;   // compostion
    LexicalAnalyzer lexicalAnalyzer; // compostion
public:
    std::shared_ptr<ICommand> parse(std::istream &inputStream);
};