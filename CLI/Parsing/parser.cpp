#include "parser.hpp"

std::shared_ptr<ICommand> Parser::parse(std::istream &inputStream)
{
    std::cout << "Enter command: ";
    syntaxAnalyzer.reset();

    Token token;
    Command cmd;
    
    try
    {
        while (token.tokenType != Token::Type::EOC)
        {
            token = lexicalAnalyzer.getToken(inputStream);
            cmd = syntaxAnalyzer.processInput(token);

            if (syntaxAnalyzer.getCurrentState() == ParserStates::Error)
            {
                if (token.tokenType == Token::Type::Unknown)
                {
                    std::cerr << "Unknown symbol: ";
                    std::visit([](const auto &v)
                               { std::cerr << v << std::endl; }, token.value);
                
                    //throw std::invalid_argument("");
                    return nullptr;
                }
                throw std::invalid_argument("Unexpected value without option.");
                return nullptr;
            }
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Syntax analysis error: " << e.what() << std::endl;
        return nullptr;
    }

    // std::cout << cmd.cmdName << "\n";
    // for (const auto &arg : cmd.argList)
    // {
    //     std::cout << "Key: " << arg.first << ", Value: ";
    //     if (std::holds_alternative<std::string>(arg.second))
    //         std::cout << std::get<std::string>(arg.second) << "\n";
    //     else if (std::holds_alternative<double>(arg.second))
    //         std::cout << std::get<double>(arg.second) << "\n";
    // }

    try
    {
        std::shared_ptr<ICommand> commandPtr = CommandCreator::semanticAnalizer(cmd);
        return commandPtr;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Semantic analysis error: " << e.what() << std::endl;
        return nullptr;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Syntax analysis error: " << e.what() << std::endl;
        return nullptr;
    }

    return nullptr;
}