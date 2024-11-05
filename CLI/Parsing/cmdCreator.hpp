#pragma once
#include "syntaxAnalyzer.hpp"
#include <memory>
#include <map>
#include <iostream>
#include "../Command_Execution/includes/ICommand.hpp"
#include "../Command_Execution/includes/commands.hpp"
#include <unordered_map>
#include <functional>
#include "../controller.hpp"


class CommandCreator {
public:
    static std::map<std::string, std::vector<std::string>> createCmdPrototypes();
    static std::shared_ptr<ICommand> semanticAnalizer(Command cmd);
    static std::map<std::string, std::vector<std::string>> m_CmdPrototypes;    
};