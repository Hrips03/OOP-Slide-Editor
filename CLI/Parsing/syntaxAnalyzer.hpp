#pragma once
#include "../includes.hpp"
#include "lexicalAnalyzer.hpp"

enum class parserStates //TK: Please always start type names with Capital letter 
{
    Start,
    Command,
    Argument,
    Error,
    Finish
};


class SyntaxAnalyzer
{
private:
    parserStates currentState;

public:
    SyntaxAnalyzer() : currentState(parserStates::Start) {}
    void reset();
    Token processInput(Token input);
    void printCurrentState();
    parserStates getCurrentState() const;
};


