#include "lexicalAnalyzer.hpp"

Token LexicalAnalyzer::getToken(std::string input, int &position)
{
    // std::cout << "input = " <<input << std::endl;
    // std::cout << "position = " <<position << std::endl;

    while (position < input.size() && std::isspace(input[position]))
        position++;

    char currentChar = input[position];

    if (currentChar == '-')
    {
        metOption = true;
        position++;
        std::string option;

        if (position < input.size() && std::isalpha(input[position]))
        {
            option += input[position];
            position++;

            while (position < input.size() && std::isalnum(input[position]))
            {
                option += input[position];
                position++;
            }

            //std::cout << "Token::Type::Option  =  " << option << "\n";
            return Token{Token::Type::Option, option};
        }
        else
        {
            //std::cout << "Token::Type::Unknown  =  " << std::string(1, currentChar) << "\n";
            return Token{Token::Type::Unknown, std::string(1, currentChar)};
        }

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
        //std::cout << "Token::Type::Value  =  " << value << "\n";
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
        
        if (metOption)
        {
            //std::cout << "Token::Type::Value  =  " << word << "\n";
            return Token{Token::Type::Value, word};
        }
        else
        {
            //std::cout << "Token::Type::Word  =  " << word << "\n";
            return Token{Token::Type::Word, word};
        }
    }

    //std::cout << "Token::Type::Unknown  =  " << std::string(1, input[position]) << "\n";
    return Token{Token::Type::EOC, ""};
}
