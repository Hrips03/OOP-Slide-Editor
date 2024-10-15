#pragma once
#include "lexicalAnalyzer.hpp"
#include "../includes.hpp"


class CommandCreator
{
public:
    bool semanticAnalizer(std::vector<Token>);
    std::map<std::string, std::vector<std::string>> createCmdPrototypes();
    //virtual void execute() = 0;
};