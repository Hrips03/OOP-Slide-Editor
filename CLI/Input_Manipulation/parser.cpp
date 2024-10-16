#include "parser.hpp"

std::shared_ptr<ICommand> Parser::parse(std::stringstream &inputStream)
{
    Token token;
    std::vector<Token> tokenVector;
    inputStream << " ";

    int position = 0;
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
                break;
            }
            // TO DO: add accurate error handling
            std::cerr << "Parsing aborted due to syntax error. See help to learn syntax." << std::endl;
            break;
        }

        tokenVector.push_back(token);
    }

    Command cmd;
    if (syntaxAnalyzer.getCurrentState() == parserStates::Finish)
        cmd = command.lock()->semanticAnalizer(tokenVector);


    // std::cout << cmd.cmdName << "\n";

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


    //validCmd = std::make_shared<CommandCreator> cmd; //this is incorrect
    
    return validCmd;
}