#include "parser.hpp"

// Parser::Parser(std::string input) : input(input), position(0) {}

void Parser::parse(){
    syntaxAnalyzer.processInput(lexicalAnalyzer.getToken().tokenType);
}

