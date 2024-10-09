#include "includes.hpp"

class Parser
{
    // std::string input;
    // size_t position;

    SyntaxAnalyzer syntaxAnalyzer;   // compostion
    LexicalAnalyzer lexicalAnalyzer; // compostion

public:
    //Parser(std::string input);
    void parse();
};