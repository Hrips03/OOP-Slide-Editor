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
public:
    Token getToken(std::string input, int& position);    
};