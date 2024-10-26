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
    bool m_metOption = false;
public:
    Token getToken(std::istream &inputStream);    
};