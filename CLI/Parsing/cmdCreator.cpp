#include "cmdCreator.hpp"
#include "../Command_Execution/includes/commands.hpp"
#include "../../Document/includes/shapes.hpp"

std::map<std::string, std::vector<std::string>> CommandCreator::createCmdPrototypes()
{
    std::map<std::string, std::vector<std::string>> optionsMap;

    optionsMap["add slide"] = {"pos"};
    optionsMap["remove slide"] = {"pos"};

    optionsMap["add shape"] = {"x", "y", "slide", "col"};
    optionsMap["remove shape"] = {"x", "y", "slide", "col"};

    optionsMap["print slide"] = {"pos"};

    optionsMap["help"];
    optionsMap["exit"];

    return optionsMap;
}

std::map<std::string, std::vector<std::string>> CommandCreator::m_CmdPrototypes = createCmdPrototypes();

std::unordered_map<std::string, std::unique_ptr<ICommand>> prototypeFactory = {
    {"add slide", std::make_unique<addSlide>()},
    {"remove slide", std::make_unique<removeSlide>()},
    {"add shape", std::make_unique<addShape>()},
    {"remove shape", std::make_unique<removeShape>()},
    {"print slide", std::make_unique<printSlide>()},
    // {"exit", std::make_unique<exit>()},
    {"help", std::make_unique<help>()}
};

std::unique_ptr<ICommand> CommandCreator::semanticAnalizer(Command cmd)
{
    std::string command = cmd.cmdName;
    auto it = m_CmdPrototypes.find(command);

    if (it == m_CmdPrototypes.end())
    {
        std::cerr << "Unknown command: " << command << std::endl;
        throw std::runtime_error("Unknown command: " + command + ".");
    }

    std::vector<std::string> expectedOptions = it->second;

    for (const std::string &option : expectedOptions)
    {
        auto it = cmd.argList.find(option);
        if (it != cmd.argList.end())
        {
           return it->second->clone();
        }
        else
        {
            throw std::invalid_argument("Unknown command type");
        }
    }

    std::unique_ptr<ICommand> pCmd = it->second;
    return pCmd;
}
