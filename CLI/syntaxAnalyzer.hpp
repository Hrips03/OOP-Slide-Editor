#include "includes.hpp"

enum class parserStates
{
    Start,
    Command,
    Argument,
    Error,
    Finish
};

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

class SyntaxAnalyzer
{
private:
    parserStates currentState;

public:
    SyntaxAnalyzer() : currentState(parserStates::Start) {}

    void processInput(Token::Type input);
    void printCurrentState();
};