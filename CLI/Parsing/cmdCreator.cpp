#include "cmdCreator.hpp"

std::map<std::string, std::vector<std::string>> CommandCreator::createCmdPrototypes()
{
    //TK: This map should be static and initialized only once 
    std::map<std::string, std::vector<std::string>> optionsMap;

    optionsMap["add slide"] = {"pos"};
    optionsMap["remove slide"] = {"pos"};

    optionsMap["add rect"] = {"pos1", "pos2", "slide", "col"};
    optionsMap["remove rect"] = {"pos1", "pos2", "slide"};

    optionsMap["add triangle"] = {"pos1", "pos2", "slide","col"};
    optionsMap["remove triangle"] = {"pos1", "pos2", "slide"};

    optionsMap["add circle"] = {"pos1", "pos2", "slide", "col"};
    optionsMap["remove circle"] = {"pos1", "pos2", "slide"};

    optionsMap["print slide"] = {"pos"};
    
    optionsMap["help"];
    optionsMap["exit"];
    optionsMap["print slides"];
    
    return optionsMap;
}

Command CommandCreator::semanticAnalizer(std::vector<Token> tokens)
{
    //TK: createCmdPrototypes() called each time, indeed?
    std::map<std::string, std::vector<std::string>> prototypes = createCmdPrototypes();
    
    std::string command = std::get<std::string>(tokens[0].value);
    size_t tokenIndex = 1;

    if (tokens[1].tokenType == Token::Type::Word)
    {
        command += " " + std::get<std::string>(tokens[1].value);
        tokenIndex++;
    }
    
    auto it = prototypes.find(command);

    if (it == prototypes.end())
    {
        std::cerr << "Unknown command: " << command << std::endl;
        throw std::runtime_error("Unknown command: " + command + ".");
    }

    std::vector<std::string> expectedOptions = it->second;
    std::map<std::string, std::variant<std::string, double>> argumentList;

    for (const std::string &option : expectedOptions)
    {
        if (tokens[tokenIndex].tokenType != Token::Type::Option ||
            !std::holds_alternative<std::string>(tokens[tokenIndex].value) ||
            std::get<std::string>(tokens[tokenIndex].value) != option)
        {
            if (option == "col" && tokens[tokenIndex + 1].tokenType != Token::Type::Value)
                continue;
            throw std::runtime_error("Expected option: '" + option + "' after command: " + command);
        }

        tokenIndex++;

        if (option == "pos" || option == "pos1" || option == "pos2" || option == "slide")
        {
            if (tokenIndex >= tokens.size() ||
                tokens[tokenIndex].tokenType != Token::Type::Value ||
                !std::holds_alternative<double>(tokens[tokenIndex].value))
            {
                throw std::runtime_error("Expected position number after: '" + option + "' command.");
            }
        }

        if (option == "col")
        {
            if (tokenIndex >= tokens.size() ||
                tokens[tokenIndex].tokenType != Token::Type::Value ||
                !std::holds_alternative<std::string>(tokens[tokenIndex].value))
            {
                throw std::runtime_error("Expected color name after: '" + option + "' command.");
            }
        }
        argumentList[option] = tokens[tokenIndex].value;
        tokenIndex++;

    }

    //std::cout << "Command is semantically valid for command: " << command << std::endl;
    
    Command cmd;
    cmd.cmdName = command;
    cmd.argList = argumentList;
    return cmd;
}
