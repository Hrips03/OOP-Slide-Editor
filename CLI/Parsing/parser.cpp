#include "parser.hpp"

std::shared_ptr<ICommand> Parser::parse(std::istream &inputStream)
{
    if (typeid(inputStream) != typeid(std::ifstream)) 
        std::cout << "Enter command: ";

    syntaxAnalyzer.reset();

    Token token;
    Command cmd;

    try
    {
        while (syntaxAnalyzer.getCurrentState() != ParserStates::Finish)
        {
            token = lexicalAnalyzer.getToken(inputStream);
            cmd = syntaxAnalyzer.processInput(token);
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Syntax analysis error: " << e.what() << std::endl;
        inputStream.clear(); 
        inputStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
        std::cerr << "Semantic analysis error: " << e.what() << std::endl;
        return nullptr;
    }

    return nullptr;
}