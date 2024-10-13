#include "parser.hpp"

void Parser::parse(std::string input)
{
    Token token;
    std::vector<Token> tokenVector;
    while (position < input.size())
    {
        token = lexicalAnalyzer.getToken(input, position);
        syntaxAnalyzer.processInput(token);
    

        //kinda error handling
        if (syntaxAnalyzer.getCurrentState() == parserStates::Error)
        {
            if (token.tokenType == Token::Type::Unknown)
            {
                std::cerr << "Unknown symbol: ";
                std::visit([](const auto &v)
                           { std::cout << v << std::endl; }, token.value);
                break;
            }
            // TO DO: add accurate error handling
            std::cerr << "Parsing aborted due to syntax error. Command must look like this: word[word] [arg[value]]"
                      << std::endl;
            break;
        }

        tokenVector.push_back(token);
    }
    command.lock()->semanticAnalizer(tokenVector);
    


}