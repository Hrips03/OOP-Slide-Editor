#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Parser
{
    int argc;
    std::vector<std::string> argv;

   public:
    Parser(int argc, char *argv[]);
    void printCLI();
    void validateInput();
};