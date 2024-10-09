#include "lexicalAnalyzer.hpp"

LexicalAnalyzer::LexicalAnalyzer(std::string input) : input(input) {}

Token LexicalAnalyzer::getToken()
{
    while (position < input.size() && input[position] == ' ')
    {
        position++;
    }

    if (position >= input.size())
    {
        return Token{Token::Type::EOC, ""};
    }

    if (input[position] == '-')
    {
        position++;
        std::string option;
        while (position < input.size() && std::isalpha(input[position]))
        {
            option += input[position];
            position++;
        }
        return Token{Token::Type::Option, option};
    }

    if (std::isdigit(input[position]))
    {
        int value = 0;
        while (position < input.size() && std::isdigit(input[position]))
        {
            value = value * 10 + (input[position] - '0');
            position++;
        }
        return Token{Token::Type::Value, value};
    }

    std::string word;
    while (position < input.size() && std::isalpha(input[position]))
    {
        word += input[position];
        position++;
    }
    return Token{Token::Type::Word, word};
}
