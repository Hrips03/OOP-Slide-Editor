#pragma once
#include "syntaxAnalyzer.hpp"
// #include "../includes.hpp"
#include <memory>
#include <map>
#include <vector>
#include <iostream>
#include "CLI/Command_Execution/includes/ICommand.hpp"
#include "CLI/Command_Execution/includes/commands.hpp"
// struct Command{
//     std::string cmdName;
//     std::map<std::string, std::variant<std::string, double>> argList;
// };

class CommandCreator
{
    static std::map<std::string, std::unique_ptr<ICommand>> m_CmdPrototypes;
public:
    std::unique_ptr<ICommand> Create(Command);
    void Register(std::unique_ptr<ICommand>);

    std::unique_ptr<ICommand> semanticAnalizer(Command);
    static std::map<std::string, std::unique_ptr<ICommand>> createCmdPrototypes();
};