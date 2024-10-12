#include "lexicalAnalyzer.hpp"

Token LexicalAnalyzer::getToken(std::string input, int &position)
{
    while (position < input.size() && std::isspace(input[position]))
        position++;

    if (position >= input.size())
    {
        std::cout << "Token::Type::EOC  =  ' '" << "\n";
        return Token{Token::Type::EOC, ""};
    }

    char currentChar = input[position];

    if (currentChar == '-')
    {
        position++;
        std::string option;
        while (position < input.size() && std::isalpha(input[position]))
        {
            option += input[position];
            position++;
        }
        std::cout << "Token::Type::Option  =  " << option << "\n";
        return Token{Token::Type::Option, option};
    }

    if (std::isdigit(currentChar) || (currentChar == '.' && std::isdigit(input[position + 1])))
    {
        std::string numStr;
        while (position < input.size() && std::isdigit(input[position]))
        {
            numStr += input[position];
            position++;
        }

        if (position < input.size() && input[position] == '.')
        {
            numStr += '.';
            position++;

            while (position < input.size() && std::isdigit(input[position]))
            {
                numStr += input[position];
                position++;
            }
        }

        double value = std::stod(numStr);
        std::cout << "Token::Type::Value  =  " << value << "\n";
        return Token{Token::Type::Value, value};
    }

    if (std::isalpha(currentChar))
    {
        std::string word;
        while (position < input.size() && std::isalpha(input[position]))
        {
            word += input[position];
            position++;
        }
        std::cout << "Token::Type::Word  =  " << word << "\n";
        return Token{Token::Type::Word, word};
    }

    std::cout << "Token::Type::Unknown  =  " << std::string(1, input[position])<< "\n";
    return Token{Token::Type::Unknown, std::string(1, input[position++])};
}
