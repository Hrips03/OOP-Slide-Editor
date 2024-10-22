#include "parser.hpp"
#include "../commandAdapter.hpp"

std::shared_ptr<ICommand> Parser::parse(std::stringstream &inputStream)
{
    syntaxAnalyzer.reset();
    Token token;
    std::vector<Token> tokenVector;
    inputStream << " ";

    int position = 0; //TK: no position, no checks, parser should not handle input stream directly
    
    /* for example
    //TK: pass stream to token, also no need to keep vector of Tokens  
    token = lexicalAnalyzer.getToken(inputStream); 
    whule (token.tokenType != Token::Type::EOC) 
    {
        syntaxAnalyzer.processInput(token);
        ...
        token = lexicalAnalyzer.getToken(inputStream.str(), position); 
    }
    */


    while (position < inputStream.str().size())
    {
        token = lexicalAnalyzer.getToken(inputStream.str(), position); 
        syntaxAnalyzer.processInput(token);

        if (syntaxAnalyzer.getCurrentState() == parserStates::Error)
        {
            if (token.tokenType == Token::Type::Unknown)
            {
                std::cerr << "Unknown symbol: ";
                std::visit([](const auto &v)
                           { std::cout << v << std::endl; }, token.value);
                return nullptr;
            }
            // TO DO: add accurate error handling
            std::cerr << "Parsing aborted due to syntax error. See help to learn syntax." << std::endl;
            return nullptr;
        }

        tokenVector.push_back(token);
    }
    
    Command cmd;
    try
    {
        if (syntaxAnalyzer.getCurrentState() == parserStates::Finish)
            //TK: use prefix like m_* to distinguish memebers from locals, also do not use identical names different by only first letter case
            cmd = command.lock()->semanticAnalizer(tokenVector);
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return nullptr;
    }

    //std::cout << cmd.cmdName << "\n";

    // for (const auto &arg : cmd.argList)
    // {
    //     std::cout << "Key: " << arg.first << ", Value: ";

    //     // Check if the value is a string or a double using std::holds_alternative
    //     if (std::holds_alternative<std::string>(arg.second))
    //     {
    //         std::cout << std::get<std::string>(arg.second) << "\n";
    //     }
    //     else if (std::holds_alternative<double>(arg.second))
    //     {
    //         std::cout << std::get<double>(arg.second) << "\n";
    //     }
    // }
    
    return std::make_shared<CommandAdapter>(cmd);
}