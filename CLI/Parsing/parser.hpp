#pragma once
#include "syntaxAnalyzer.hpp"
#include "cmdCreator.hpp"
//#include "../Command_Execution/includes/ICommand.hpp"

class Parser
{
    SyntaxAnalyzer syntaxAnalyzer;   // compostion
    LexicalAnalyzer lexicalAnalyzer; // compostion

    //std::weak_ptr<CommandCreator> command; //association
    //std::shared_ptr<ICommand> validCmd;     //agregation
    //ICommand* validCmd;
public:
    std::shared_ptr<ICommand> parse(std::istream &inputStream);
    //void parse(std::istream &inputStream);

};