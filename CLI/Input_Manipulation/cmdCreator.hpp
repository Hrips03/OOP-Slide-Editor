#pragma once
#include "lexicalAnalyzer.hpp"
#include "../includes.hpp"

struct Command{
    std::string cmdName;
    std::map<std::string, std::variant<std::string, double>> argList;
};

class CommandCreator
{
    //Command cmd;
public:
    Command semanticAnalizer(std::vector<Token>);
    std::map<std::string, std::vector<std::string>> createCmdPrototypes();
};