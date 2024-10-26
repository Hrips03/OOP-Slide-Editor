#include "lexicalAnalyzer.hpp"

Token LexicalAnalyzer::getToken(std::istream &inputStream)
{
    char ch;
    while (inputStream.get(ch) && ch == ' ');

    if (ch == '\n')
        return {Token::Type::EOC, {}};
    

    if (ch == '-')
    {
        std::string option;
        while (inputStream.get(ch) && (std::isalnum(ch) || ch == '_'))
        {
            option += ch;
        }
        inputStream.putback(ch); 
        m_metOption = true;

        std::cout << "Token::Type::Option = " << option << std::endl;
        return {Token::Type::Option, option};
    }

  
    if (std::isalpha(ch))
    {
        std::string word;
        word += ch;
        while (inputStream.get(ch) && std::isalpha(ch))
        {
            word += ch;
        }
        inputStream.putback(ch); 
        
        std::cout << "Token::Type::Word = " << word << std::endl;
        return {Token::Type::Word, word};
    }


    if (std::isdigit(ch) || ch == '.')
    {
        std::string number;
        number += ch;
        bool hasDecimal = (ch == '.');
        while (inputStream.get(ch))
        {
            if (std::isdigit(ch))
                number += ch;
            else if (ch == '.' && !hasDecimal)
            {
                number += ch;
                hasDecimal = true;
            }
            else
            {
                inputStream.putback(ch); 
                break;
            }
        }
        std::cout << "Token::Type::Value = " << number << std::endl;
        return {Token::Type::Value, std::stod(number)};
    }

    //throw std::runtime_error("Unexpected symbol.");
    std::cout << "Token::Type::Unknown = " << ch << std::endl;
    return {Token::Type::Unknown, {}};
}
