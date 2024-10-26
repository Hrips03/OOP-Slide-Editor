#include "cmdCreator.hpp"
#include "../Command_Execution/includes/commands.hpp"



std::map<std::string, std::unique_ptr<ICommand>> CommandCreator::createCmdPrototypes()
{
    std::map<std::string, std::unique_ptr<ICommand>> optionsMap;

    optionsMap["add slide"] = std::make_unique<addSlide>({"pos"});
    optionsMap["remove slide"] = std::make_unique<remSlide>({"pos"});

    optionsMap["add shape"] = std::make_unique<addShape>({ShapeType, Geometry, Attributes});
    optionsMap["remove shape"] = std::make_unique<remShape>({ShapeType, Geometry, Attributes});

    optionsMap["print slide"] = std::make_unique<printSlide>({"pos"});

    optionsMap["help"];
    optionsMap["exit"];

    return optionsMap;
}

std::map<std::string, std::unique_ptr<ICommand>> CommandCreator::m_CmdPrototypes = createCmdPrototypes();

std::unique_ptr<ICommand> CommandCreator::semanticAnalizer(Command cmd)
{
<<<<<<< HEAD
    // std::string command = std::get<std::string>(tokens[0].value);
    // size_t tokenIndex = 1;
=======
    //TK: createCmdPrototypes() called each time, indeed?
    std::map<std::string, std::vector<std::string>> prototypes = createCmdPrototypes();
    
    std::string command = std::get<std::string>(tokens[0].value);
    size_t tokenIndex = 1;
>>>>>>> 3b9ef6fda2f87c5472f08af14829b53242f1fb23

    // if (tokens[1].tokenType == Token::Type::Word)
    // {
    //     command += " " + std::get<std::string>(tokens[1].value);
    //     tokenIndex++;
    // }

    std::string command = cmd.cmdName; 
    auto it = m_CmdPrototypes.find(command);

    if (it == m_CmdPrototypes.end())
    {
        std::cerr << "Unknown command: " << command << std::endl;
        throw std::runtime_error("Unknown command: " + command + ".");
    }

    std::unique_ptr<ICommand> pCmd = it->clone(cmd.argList);
    return pCmd;

    for (optn : cmd.options)
        it->option.find(optn)

            std::unique_ptr<ICommand> pCmd = it->second();

    std::vector<std::string> expectedOptions = it->second;
    // std::map<std::string, std::variant<std::string, double>> argumentList;

    // for (const std::string &option : expectedOptions)
    // {
    //     if (tokens[tokenIndex].tokenType != Token::Type::Option ||
    //         !std::holds_alternative<std::string>(tokens[tokenIndex].value) ||
    //         std::get<std::string>(tokens[tokenIndex].value) != option)
    //     {
    //         if (option == "col" && tokens[tokenIndex + 1].tokenType != Token::Type::Value)
    //             continue;
    //         throw std::runtime_error("Expected option: '" + option + "' after command: " + command);
    //     }

    //     tokenIndex++;

    //     if (option == "pos" || option == "pos1" || option == "pos2" || option == "slide")
    //     {
    //         if (tokenIndex >= tokens.size() ||
    //             tokens[tokenIndex].tokenType != Token::Type::Value ||
    //             !std::holds_alternative<double>(tokens[tokenIndex].value))
    //         {
    //             throw std::runtime_error("Expected position number after: '" + option + "' command.");
    //         }
    //     }

    //     if (option == "col")
    //     {
    //         if (tokenIndex >= tokens.size() ||
    //             tokens[tokenIndex].tokenType != Token::Type::Value ||
    //             !std::holds_alternative<std::string>(tokens[tokenIndex].value))
    //         {
    //             throw std::runtime_error("Expected color name after: '" + option + "' command.");
    //         }
    //     }
    //     argumentList[option] = tokens[tokenIndex].value;
    //     tokenIndex++;
    // }

    // // std::cout << "Command is semantically valid for command: " << command << std::endl;

    // Command cmd;
    // cmd.cmdName = command;
    // cmd.argList = argumentList;
    // return cmd;
}
