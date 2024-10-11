#include "parser.hpp"

void Parser::parse(std::string input){
    //syntaxAnalyzer.processInput(lexicalAnalyzer.getToken().tokenType);

    std::cout << "parse() is called and input is: " << input << std::endl;
    lexicalAnalyzer.getToken(input, position);
}

