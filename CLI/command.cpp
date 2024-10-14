#include "command.hpp"

std::map<std::string, std::vector<std::string>> CommandCreator::createCmdPrototypes()
{
    std::map<std::string, std::vector<std::string>> optionsMap;
    
    //cli -> editor -> document -> visual
    optionsMap["addSlide"] = {"pos"};
    optionsMap["removeSlide"] = {"pos"};

    optionsMap["addShape"] = {"pos1", "pos2"};
    optionsMap["removeShape"] = {"pos1", "pos2"};
    
    //cli -> document -> visual
    optionsMap["printSlide"] = {"pos"};

    //cli -> visual
    optionsMap["help"];
    optionsMap["exit"];

    return optionsMap;
}

bool CommandCreator::semanticAnalizer(std::vector<Token> tokens)
{
    std::map<std::string, std::vector<std::string>> prototypes = createCmdPrototypes();

    std::string command = std::get<std::string>(tokens[0].value);
    auto it = prototypes.find(command);

    if (it == prototypes.end())
    {
        std::cerr << "Unknown command: " << command << std::endl;
        return false;
    }

    std::vector<std::string> expectedOptions = it->second;
    size_t tokenIndex = 1;

    // std::cout << "command = " << command << " expectedOptions = ";

    // for (const std::string &option : expectedOptions)
    // {
    //     std::cout << option << "\n";
    // }

    for (const std::string &option : expectedOptions)
    {

        if (tokens[tokenIndex].tokenType != Token::Type::Option ||
            !std::holds_alternative<std::string>(tokens[tokenIndex].value) ||
            std::get<std::string>(tokens[tokenIndex].value) != option)
        {
            std::cerr << "Expected option: '" << option << "' after command: " << command << std::endl;
            return false;
        }

        tokenIndex++;

        if (tokenIndex >= tokens.size() ||
            tokens[tokenIndex].tokenType != Token::Type::Value ||
            !std::holds_alternative<double>(tokens[tokenIndex].value))
        {
            return false;
        }
        tokenIndex++;
    }

    std::cout << "Command is semantically valid for command: " << command << std::endl;
    return true;
}
