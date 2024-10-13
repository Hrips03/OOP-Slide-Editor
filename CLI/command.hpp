#pragma once
#include "lexicalAnalyzer.hpp"
#include "includes.hpp"

// enum add
// {
//     slide,
//     shape
// };

// enum remove
// {
//     slide,
//     shape
// };

// enum slide
// {
//     pos
// };

// enum shape
// {
//     pos1,
//     pos2
// };

// enum print
// {
//     slide
// };




class CommandCreator
{
public:
    bool semanticAnalizer(std::vector<Token>);
    std::map<std::string, std::vector<std::string>> createCmdPrototypes();
    //virtual void execute() = 0;
};