#pragma once
#include "../includes.hpp"

struct Token
{
    enum class Type
    {
        Word,
        Option,
        Value,
        EOC, 
        Unknown
    };

    Type tokenType;
    std::variant<std::string, double> value;
};

class LexicalAnalyzer
{
    bool metOption = false;
public:
    //TK: getToken should accpet istream not string
    Token getToken(std::string input, int& position);    
};