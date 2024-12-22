#include "cmdCreator.hpp"

std::map<std::string, std::vector<std::string>> CommandCreator::createCmdPrototypes()
{
    std::map<std::string, std::vector<std::string>> optionsMap;

    optionsMap["add slide"] = {"pos"};
    optionsMap["remove slide"] = {"pos"};
    optionsMap["add shape"] = {"x", "y", "type", "slide", "height", "width", "col", "outlineCol"};
    optionsMap["remove shape"] = {"slide", "shape"};
    optionsMap["change geom"] = {"slide", "shape", "x", "y", "height", "width"};
    optionsMap["print slide"] = {"pos"};
    optionsMap["print slides"] = {};
    optionsMap["save"] = {"fileName"};
    optionsMap["load"] = {"fileName"};
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
    if (typeStr == "Ellipse" || typeStr == "ellipse")
        return Item::ShapeType::Ellipse;
    else if (typeStr == "Rectangle" || typeStr == "rectangle")
        return Item::ShapeType::Rectangle;
    else if (typeStr == "Triangle" || typeStr == "triangle")
        return Item::ShapeType::Triangle;

    throw std::invalid_argument("Invalid shape type: " + typeStr);
}

std::unordered_map<std::string, std::function<std::shared_ptr<ICommand>(const Command &)>> prototypeFactory = {
    {"add slide", [](const Command &cmd)
     {
         try
         {
             return std::make_shared<addSlide>(
                 static_cast<int>(std::get<double>(cmd.argList.at("pos"))));
         }
         catch (const std::out_of_range &)
         {
             throw std::runtime_error("Error: Missing required argument 'pos' for 'add slide'. Expected a double.");
         }
         catch (const std::bad_variant_access &)
         {
             throw std::runtime_error("Error: Argument 'pos' for 'add slide' must be of type double.");
         }
     }},

    {"remove slide", [](const Command &cmd)
     {
         try
         {
             return std::make_shared<removeSlide>(
                 static_cast<int>(std::get<double>(cmd.argList.at("pos"))));
         }
         catch (const std::out_of_range &)
         {
             throw std::runtime_error("Error: Missing required argument 'pos' for 'remove slide'. Expected a double.");
         }
         catch (const std::bad_variant_access &)
         {
             throw std::runtime_error("Error: Argument 'pos' for 'remove slide' must be of type double.");
         }
     }},

    {"add shape", [](const Command &cmd)
     {
         try
         {
             std::shared_ptr<Item> item = std::make_shared<Item>();
             item->geom = {
                 getArgValueOrDefault(cmd, "x", 0.0),
                 getArgValueOrDefault(cmd, "y", 0.0),
                 getArgValueOrDefault(cmd, "height", 10.0),
                 getArgValueOrDefault(cmd, "width", 10.0)};
             item->attribs = {
                 getArgValueOrDefault<std::string>(cmd, "col", "white"),
                 getArgValueOrDefault<std::string>(cmd, "outlineCol", "black")};
             item->type = stringToShapeType(std::get<std::string>(cmd.argList.at("type")));
             return std::make_shared<addShape>(
                 static_cast<int>(std::get<double>(cmd.argList.at("slide"))),
                 item);
         }
         catch (const std::out_of_range &e)
         {
             throw std::runtime_error("Error: Missing required argument for 'add shape'.");
         }
         catch (const std::bad_variant_access &)
         {
             throw std::runtime_error("Error: One of the arguments for 'add shape' is of the wrong type. "
                                      "Expected 'x' and 'y' as doubles, 'type' as string, and 'slide' as double.");
         }
     }},

    {"remove shape", [](const Command &cmd)
     {
         try
         {
             return std::make_shared<removeShape>(
                 static_cast<int>(std::get<double>(cmd.argList.at("slide"))),
                 static_cast<int>(std::get<double>(cmd.argList.at("shape"))));
         }
         catch (const std::out_of_range &e)
         {
             throw std::runtime_error("Error: Missing required argument for 'remove shape'.");
         }
         catch (const std::bad_variant_access &)
         {
             throw std::runtime_error("Error: One of the arguments for 'remove shape' is of the wrong type. "
                                      "Expected 'x' and 'y' as doubles, 'type' as string, and 'slide' as double.");
         }
     }},

    {"change geom", [](const Command &cmd)
     {
         try
         {
             Item::Geometry itemGeom;
             itemGeom = {
                 getArgValueOrDefault(cmd, "x", 0.0),
                 getArgValueOrDefault(cmd, "y", 0.0),
                 getArgValueOrDefault(cmd, "height", 0.0),
                 getArgValueOrDefault(cmd, "width", 0.0)};

            Item::Attributes itemAttrs;
            itemAttrs = {
                 getArgValueOrDefault<std::string>(cmd, "col", "white"),
                 getArgValueOrDefault<std::string>(cmd, "outlineCol", "black")};
             return std::make_shared<changeGeometry>(
                 static_cast<int>(std::get<double>(cmd.argList.at("slide"))),
                 static_cast<int>(std::get<double>(cmd.argList.at("shape"))),
                 itemGeom, itemAttrs);
         }
         catch (const std::bad_variant_access &)
         {
             throw std::runtime_error("Error: One of the arguments for 'change geom' is of the wrong type. "
                                      "Expected doubles.");
         }
     }},

    {"print slide", [](const Command &cmd)
     {
         try
         {
             return std::make_shared<printSlide>(
                 static_cast<int>(getArgValueOrDefault(cmd, "pos", 0.0)));
         }
         catch (const std::bad_variant_access &)
         {
             throw std::runtime_error("Error: Argument 'pos' for 'print slide' must be of type double.");
         }
     }},

    {"print slides", [](const Command &)
     {
         return std::make_shared<printSlides>();
     }},
    {"help", [](const Command &)
     {
         return std::make_shared<help>();
     }},
     {"save", [](const Command &cmd)
     {
         return std::make_shared<saveCmd>(std::get<std::string>(cmd.argList.at("fileName")));
     }},
     {"load", [](const Command &cmd)
     {
         return std::make_shared<loadCmd>(std::get<std::string>(cmd.argList.at("fileName")));
     }},
    {"exit", [](const Command &)
     {
         return std::make_shared<exitCmd>(Controller::exitPtr);
     }},
    {"undo", [](const Command &)
     {
         return std::make_shared<UndoCmd>();
     }},
    {"redo", [](const Command &)
     {
         return std::make_shared<RedoCmd>();
     }}};

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
            // Skip optional arguments
            if (option == "col" || option == "outlineCol" || option == "height" || option == "width" || option == "x" || option == "y")
                continue;

            throw std::runtime_error("Missing required option: " + option);
        }

        const auto &value = argIt->second;

        if (std::holds_alternative<double>(value))
            continue;
        else if (std::holds_alternative<std::string>(value))
            if (std::get<std::string>(value).empty())
                throw std::invalid_argument("Option '" + option + "' cannot be empty.");
    }

    for (const auto &arg : cmd.argList)
    {
        if (std::find(expectedOptions.begin(), expectedOptions.end(), arg.first) == expectedOptions.end())
        {
            // Skip optional arguments
            static const std::unordered_set<std::string> optionalArgs = {"x", "y", "height", "width", "col", "outlineCol"};
            if (optionalArgs.find(arg.first) != optionalArgs.end())
            {
                continue;
            }

            throw std::runtime_error("Unexpected option: " + arg.first);
        }
    }

    return prototypeFactory.at(command)(cmd);
}
