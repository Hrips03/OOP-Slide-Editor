#include "command.hpp"

//some trash code that does't work


std::map<std::string, std::vector<std::string>> CommandCreator::createCmdPrototypes()
{
    std::map<std::string, std::vector<std::string>> optionsMap;

    optionsMap["add"] = {"slide", "shape"};
    optionsMap["slide"] = {"pos"};
    optionsMap["remove"] = {"slide", "shape"};
    optionsMap["shape"] = {"pos1", "pos2"};
    optionsMap["print"] = {"slide"};
    optionsMap["pos"];
    optionsMap["pos1"];
    optionsMap["pos2"];

    return optionsMap;
}


bool CommandCreator::semanticAnalizer(std::vector<Token> tokens) {
    std::map<std::string, std::vector<std::string>> prototypes = createCmdPrototypes();

    if (tokens.empty()) {
        std::cerr << "No tokens provided!" << std::endl;
        return false;
    }

  
    if (tokens[0].tokenType != Token::Type::Word || !std::holds_alternative<std::string>(tokens[0].value)) {
        std::cerr << "Invalid or missing command!" << std::endl;
        return false;
    }


    std::string command = std::get<std::string>(tokens[0].value);
    auto it = prototypes.find(command);

    if (it == prototypes.end()) {
        std::cerr << "Unknown command: " << command << std::endl;
        return false;
    }


    std::vector<std::string> expectedOptions = it->second;
    size_t tokenIndex = 1;  

    for (const std::string& option : expectedOptions) {

        if (tokenIndex >= tokens.size()) {
            std::cerr << "Missing option: '" << option << "' after command: " << command << std::endl;
            return false;
        }


        if (tokens[tokenIndex].tokenType != Token::Type::Word || 
            !std::holds_alternative<std::string>(tokens[tokenIndex].value) || 
            std::get<std::string>(tokens[tokenIndex].value) != option) {
            std::cerr << "Expected option: '" << option << "' after command: " << command << std::endl;
            return false;
        }

        tokenIndex++;

 
        if (option == "-pos" || option == "-pos1" || option == "-pos2") {
            if (tokenIndex >= tokens.size() || 
                tokens[tokenIndex].tokenType != Token::Type::Value || 
                !std::holds_alternative<int>(tokens[tokenIndex].value) || 
                std::get<int>(tokens[tokenIndex].value) <= 0) {
                std::cerr << "Expected a number greater than 0 after '" << option << "'" << std::endl;
                return false;
            }
            tokenIndex++;  
        }
    }

    std::cout << "Command is semantically valid for command: " << command << std::endl;
    return true;
}
