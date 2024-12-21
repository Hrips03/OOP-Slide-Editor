#pragma once
#include "../includes.hpp"
#include "lexicalAnalyzer.hpp"

enum class ParserStates
{
    Start,
    Command,
    Argument,
    Error,
    Finish
};


struct Command{
    std::string cmdName;
    std::map<std::string, std::variant<std::string, double>> argList;
};


class SyntaxAnalyzer
{
private:
    Command m_cmd;
    ParserStates currentState;
public:
    SyntaxAnalyzer() : currentState(ParserStates::Start) {}
    void reset();
    Command processInput(Token input);

    void printCurrentState(); //for me
    ParserStates getCurrentState() const;
};


