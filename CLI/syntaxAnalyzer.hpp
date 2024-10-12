#pragma once
#include "includes.hpp"
#include "lexicalAnalyzer.hpp"

enum class parserStates
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

    Token::Type processInput(Token::Type input);
    void printCurrentState();
    parserStates getCurrentState() const;
};


