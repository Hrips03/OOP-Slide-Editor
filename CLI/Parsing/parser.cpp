#include "parser.hpp"
// #include "../commandAdapter.hpp"

std::shared_ptr<ICommand> Parser::parse(std::istream &inputStream)
{
    std::cout << "Enter command: ";
    syntaxAnalyzer.reset();

    Token token;
    Command cmd;
    
    token = lexicalAnalyzer.getToken(inputStream);
    while(token.tokenType != Token::Type::EOC && syntaxAnalyzer.getCurrentState() != ParserStates::Error){
        cmd = syntaxAnalyzer.processInput(token);
        token = lexicalAnalyzer.getToken(inputStream);
    }

    
    std::cout << cmd.cmdName << "\n";
    for (const auto &arg : cmd.argList)
    {
        std::cout << "Key: " << arg.first << ", Value: ";

        // Check if the value is a string or a double using std::holds_alternative
        if (std::holds_alternative<std::string>(arg.second))
        {
            std::cout << std::get<std::string>(arg.second) << "\n";
        }
        else if (std::holds_alternative<double>(arg.second))
        {
            std::cout << std::get<double>(arg.second) << "\n";
        }
    }

    // char ch;
    // while (inputStream.get(ch) && ch != '\n')
    // {
    //     if(ch == ' ') continue;
    //     token = lexicalAnalyzer.getToken(inputStream);
    //     syntaxAnalyzer.processInput(token);

    //     if (syntaxAnalyzer.getCurrentState() == parserStates::Error)
    //     {
    //         if (token.tokenType == Token::Type::Unknown)
    //         {
    //             std::cerr << "Unknown symbol: ";
    //             std::visit([](const auto &v)
    //                        { std::cout << v << std::endl; }, token.value);
    //             return nullptr;
    //         }
    //         // TO DO: add accurate error handling
    //         std::cerr << "Parsing aborted due to syntax error. See help to learn syntax." << std::endl;
    //         return nullptr;
    //     }

    //     tokenVector.push_back(token);
    // }

    // Command cmd;
    //  try
    //  {
    //      if (syntaxAnalyzer.getCurrentState() == parserStates::Finish)
    //          cmd = command.lock()->semanticAnalizer(tokenVector);
    //  }
    //  catch (const std::runtime_error &e)
    //  {
    //      std::cerr << "Error: " << e.what() << std::endl;
    //      return nullptr;
    //  }

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

    // return std::make_shared<CommandAdapter>(cmd);
}