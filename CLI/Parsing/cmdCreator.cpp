#include "cmdCreator.hpp"

std::map<std::string, std::vector<std::string>> CommandCreator::createCmdPrototypes()
{
    std::map<std::string, std::vector<std::string>> optionsMap;

    optionsMap["add slide"] = {"pos"};
    optionsMap["remove slide"] = {"pos"};
    optionsMap["add shape"] = {"x", "y", "type", "slide", "height", "width", "col", "outlineCol"};
    optionsMap["remove shape"] = {"x", "y", "type", "slide", "height", "width", "col", "outlineCol"};
    optionsMap["print slide"] = {"pos"};
    optionsMap["print slides"] = {};
    optionsMap["help"] = {};
    optionsMap["exit"] = {};
    optionsMap["undo"] = {};
    optionsMap["redo"] = {};    

    return optionsMap;
}
std::map<std::string, std::vector<std::string>> CommandCreator::m_CmdPrototypes = CommandCreator::createCmdPrototypes();

template <typename T>
T getArgValueOrDefault(const Command &cmd, const std::string &key, const T &defaultValue)
{
    auto it = cmd.argList.find(key);
    if (it != cmd.argList.end() && std::holds_alternative<T>(it->second))
    {
        return std::get<T>(it->second);
    }
    return defaultValue;
}

Item::ShapeType stringToShapeType(const std::string &typeStr)
{
    if (typeStr == "Ellipse" || typeStr == "ellipse" )
        return Item::ShapeType::Ellipse;
    else if (typeStr == "Rectangle" || typeStr == "rectangle" )
        return Item::ShapeType::Rectangle;
    else if (typeStr == "Triangle" || typeStr == "triangle")
        return Item::ShapeType::Triangle;

    throw std::invalid_argument("Invalid shape type: " + typeStr);
}

std::unordered_map<std::string, std::function<std::shared_ptr<ICommand>(const Command &)>> prototypeFactory = {
    {"add slide", [](const Command &cmd)
     {
         return std::make_shared<addSlide>(
             static_cast<int>(std::get<double>(cmd.argList.at("pos"))));
     }},
    {"remove slide", [](const Command &cmd)
     {
         return std::make_shared<removeSlide>(
             static_cast<int>(std::get<double>(cmd.argList.at("pos"))));
     }},
    {"add shape", [](const Command &cmd)
     {
         Item::Geometry geom = {
             std::get<double>(cmd.argList.at("x")),
             std::get<double>(cmd.argList.at("y")),
             getArgValueOrDefault(cmd, "height", 10.0),
             getArgValueOrDefault(cmd, "width", 10.0)};
         Item::Attributes attrs = {
             getArgValueOrDefault<std::string>(cmd, "col", "white"),
             getArgValueOrDefault<std::string>(cmd, "outlineCol", "black")};
         Item::ShapeType shapeType = stringToShapeType(std::get<std::string>(cmd.argList.at("type")));
         return std::make_shared<addShape>(
             static_cast<int>(std::get<double>(cmd.argList.at("slide"))),
             shapeType,
             geom,
             attrs);
     }},
    {"remove shape", [](const Command &cmd)
     {
         Item::Geometry geom = {
             std::get<double>(cmd.argList.at("x")),
             std::get<double>(cmd.argList.at("y")),
             getArgValueOrDefault(cmd, "height", 10.0),
             getArgValueOrDefault(cmd, "width", 10.0)};
         Item::Attributes attrs = {
             getArgValueOrDefault<std::string>(cmd, "col", "white"),
             getArgValueOrDefault<std::string>(cmd, "outlineCol", "black")};

         Item::ShapeType shapeType = stringToShapeType(std::get<std::string>(cmd.argList.at("type")));
         return std::make_shared<removeShape>(
             static_cast<int>(std::get<double>(cmd.argList.at("slide"))),
             shapeType,
             geom,
             attrs);
     }},
    {"print slide", [](const Command &cmd)
     {
         return std::make_shared<printSlide>(
             static_cast<int>(getArgValueOrDefault(cmd, "pos", 0.0)));
     }},
    {"print slides", [](const Command &)
     {
         return std::make_shared<printSlides>();
     }},
    {"help", [](const Command &)
     {
         return std::make_shared<help>();
     }},
     {"exit", [](const Command &) {
        return std::make_shared<exitCmd>(Controller::exitPtr);
    }}
    };



std::shared_ptr<ICommand> CommandCreator::semanticAnalizer(Command cmd)
{
    std::string command = cmd.cmdName;
    auto it = m_CmdPrototypes.find(command);

    if (it == m_CmdPrototypes.end())
    {
        throw std::runtime_error("Unknown command: " + command + ".");
    }

    std::vector<std::string> expectedOptions = it->second;

    for (const std::string &option : expectedOptions)
    {
        auto argIt = cmd.argList.find(option);
        if (argIt == cmd.argList.end())
        {
            if (option == "col" || option == "outlineCol" || option == "height" || option == "width")
                continue;
            throw std::runtime_error("Missing required option: " + option);
        }

        // const auto &value = argIt->second;

        // if (std::holds_alternative<double>(value))
        //     continue;
        // else if (std::holds_alternative<std::string>(value))
        //     if (std::get<std::string>(value).empty())
        //         throw std::invalid_argument("Option '" + option + "' cannot be empty.");
    }

    for (const auto &arg : cmd.argList)
        if (std::find(expectedOptions.begin(), expectedOptions.end(), arg.first) == expectedOptions.end())
            throw std::runtime_error("Unexpected option: " + arg.first);

    //std::cout << "Command is semantically correct\n";
    return prototypeFactory.at(command)(cmd);
}