#include "includes.hpp"

struct Token
{
    enum class Type
    {
        Word,
        Option,
        Value,
        EOC
    };

    Type tokenType;
    std::variant<std::string, int, double> value;
};

class LexicalAnalyzer
{
    std::string input;
    size_t position;

public:
    LexicalAnalyzer(std::string input);
    Token getToken();
};