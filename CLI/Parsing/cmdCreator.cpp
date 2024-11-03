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

Shape::ShapeType stringToShapeType(const std::string &typeStr)
{
    if (typeStr == "Circle" || typeStr == "circle" )
        return Shape::ShapeType::Circle;
    else if (typeStr == "Rectangle" || typeStr == "rectangle" )
        return Shape::ShapeType::Rectangle;
    else if (typeStr == "Triangle" || typeStr == "triangle")
        return Shape::ShapeType::Triangle;

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
         Shape::Geometry geom = {
             std::get<double>(cmd.argList.at("x")),
             std::get<double>(cmd.argList.at("y")),
             getArgValueOrDefault(cmd, "height", 10.0),
             getArgValueOrDefault(cmd, "width", 10.0)};
         Shape::Attributes attrs = {
             getArgValueOrDefault<std::string>(cmd, "col", "white"),
             getArgValueOrDefault<std::string>(cmd, "outlineCol", "black")};
         Shape::ShapeType shapeType = stringToShapeType(getArgValueOrDefault<std::string>(cmd, "type", "Circle"));
         return std::make_shared<addShape>(
             static_cast<int>(std::get<double>(cmd.argList.at("slide"))),
             shapeType,
             geom,
             attrs);
     }},
    {"remove shape", [](const Command &cmd)
     {
         Shape::Geometry geom = {
             std::get<double>(cmd.argList.at("x")),
             std::get<double>(cmd.argList.at("y")),
             getArgValueOrDefault(cmd, "height", 10.0),
             getArgValueOrDefault(cmd, "width", 10.0)};
         Shape::Attributes attrs = {
             getArgValueOrDefault<std::string>(cmd, "col", "white"),
             getArgValueOrDefault<std::string>(cmd, "outlineCol", "black")};

         Shape::ShapeType shapeType = stringToShapeType(getArgValueOrDefault<std::string>(cmd, "type", "Circle"));
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
        return std::make_shared<exitCmd>();  // Pass the controller
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
            throw std::invalid_argument("Missing required option: " + option);
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
            throw std::invalid_argument("Unexpected option: " + arg.first);

    std::cout << "Command is semantically correct\n";
    return prototypeFactory.at(command)(cmd);
}