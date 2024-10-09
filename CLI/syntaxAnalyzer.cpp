#include "syntaxAnalyzer.hpp"

void SyntaxAnalyzer::processInput(Token::Type input)
{
    switch (currentState)
    {
    case parserStates::Start:
        if (input == Token::Type::Word)
        {
            currentState = parserStates::Command;
        }
        else
        {
            currentState = parserStates::Error;
        }
        break;

    case parserStates::Command:
        if (input == Token::Type::Word)
        {
            // Stay in Command
        }
        else if (input == Token::Type::Option)
        {
            currentState = parserStates::Argument;
        }
        else if (input == Token::Type::Value)
        {
            currentState = parserStates::Error;
        }
        else if (input == Token::Type::EOC)
        {
            currentState = parserStates::Finish;
        }
        break;

    case parserStates::Argument:
        if (input == Token::Type::Word)
        {
            currentState = parserStates::Error;
        }
        else if (input == Token::Type::Option || input == Token::Type::Value)
        {
            // Stay in Argument
        }
        else if (input == Token::Type::EOC)
        {
            currentState = parserStates::Finish;
        }
        break;

    case parserStates::Finish:
        // uraaa
        break;

    case parserStates::Error:
        std::terminate; // Error message
        break;
    }

    printCurrentState();
}

void SyntaxAnalyzer::printCurrentState()
{
    std::cout << "Current State: ";
    switch (currentState)
    {
    case parserStates::Start:
        std::cout << "Start";
        break;
    case parserStates::Command:
        std::cout << "Command";
        break;
    case parserStates::Argument:
        std::cout << "Argument";
        break;
    case parserStates::Finish:
        std::cout << "Finish";
        break;
    case parserStates::Error:
        std::cout << "Error";
        break;
    }
    std::cout << std::endl;
}
