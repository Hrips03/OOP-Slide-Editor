#include "cmdCreator.hpp"

std::map<std::string, std::vector<std::string>> CommandCreator::createCmdPrototypes()
{
    std::map<std::string, std::vector<std::string>> optionsMap;

    // cli -> editor -> document -> visual
    optionsMap["add slide"] = {"pos"};
    optionsMap["remove slide"] = {"pos"};

    optionsMap["add rect"] = {"pos1", "pos2", "col", "outlineCol"};
    optionsMap["remove rect"] = {"pos1", "pos2"};

    optionsMap["add triangle"] = {"pos1", "pos2", "col", "outlineCol"};
    optionsMap["remove triangle"] = {"pos1", "pos2"};

    optionsMap["add circle"] = {"pos1", "pos2", "col", "outlineCol"};
    optionsMap["remove circle"] = {"pos1", "pos2"};

    // cli -> document -> visual
    optionsMap["print slide"] = {"pos"};

    // cli -> visual
    optionsMap["help"];
    optionsMap["exit"];

    return optionsMap;
}

Command CommandCreator::semanticAnalizer(std::vector<Token> tokens)
{
    std::map<std::string, std::vector<std::string>> prototypes = createCmdPrototypes();
    
    std::string command = std::get<std::string>(tokens[0].value);
    size_t tokenIndex = 1;

    if (tokens[1].tokenType == Token::Type::Word)
    {
        command += " " + std::get<std::string>(tokens[1].value);
        tokenIndex++;
    }
    
    // std::cout << "command = "<<command<<"\n";
    auto it = prototypes.find(command);

    if (it == prototypes.end())
    {
        std::cerr << "Unknown command: " << command << std::endl;
        std::terminate;
    }

    std::vector<std::string> expectedOptions = it->second;

    // std::cout << "command = " << command << " expectedOptions = ";

    // for (const std::string &option : expectedOptions)
    // {
    //     std::cout << option << "\n";
    // }
    std::map<std::string, std::variant<std::string, double>> argumentList;

    for (const std::string &option : expectedOptions)
    {
        // std::cout << "get = "<<std::get<std::string>(tokens[tokenIndex].value) << "\n";
        // std::cout << "option = "<<option << "\n";

        if (tokens[tokenIndex].tokenType != Token::Type::Option ||
            !std::holds_alternative<std::string>(tokens[tokenIndex].value) ||
            std::get<std::string>(tokens[tokenIndex].value) != option)
        {
            if (option == "col" || option == "outlineCol")
                continue;
            std::cerr << "Expected option: '" << option << "' after command: " << command << std::endl;
            std::terminate;
        }


        tokenIndex++;

        if (option == "pos" || option == "pos1" || option == "pos2")
        {
            if (tokenIndex >= tokens.size() ||
                tokens[tokenIndex].tokenType != Token::Type::Value ||
                !std::holds_alternative<double>(tokens[tokenIndex].value))
            {
                std::cerr << "Expected position number after: '" << option << "' command." << std::endl;
                std::terminate;
            }
        }
        argumentList[option] = tokens[tokenIndex].value;
        tokenIndex++;

    }

    std::cout << "Command is semantically valid for command: " << command << std::endl;
    Command cmd;
    cmd.cmdName = command;
    cmd.argList = argumentList;
    return cmd;
}
