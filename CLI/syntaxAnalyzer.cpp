#include "syntaxAnalyzer.hpp"

Token SyntaxAnalyzer::processInput(Token input)
{
    switch (currentState)
    {
    case parserStates::Start:

        switch (input.tokenType)
        {
        case Token::Type::Word:
            currentState = parserStates::Command;
            break;
        default:
            currentState = parserStates::Error;
            break;
        }

        break;

    case parserStates::Command:

        switch (input.tokenType)
        {
        case Token::Type::Option:
            currentState = parserStates::Argument;
            break;
        case Token::Type::EOC:
            currentState = parserStates::Finish;
            break;
        case Token::Type::Value:
        case Token::Type::Unknown:
            currentState = parserStates::Error;
            break;
        }

        break;

    case parserStates::Argument:

        switch (input.tokenType)
        {
        case Token::Type::EOC:
            currentState = parserStates::Finish;
            break;
        case Token::Type::Word:
        case Token::Type::Unknown:
            currentState = parserStates::Error;
            break;
        }

        break;

        // case parserStates::Finish:
        //     // uraaa
        //     break;

        // case parserStates::Error:
        //     std::terminate; // Error message
        //     break;
    }

    //printCurrentState();
    return input;
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

parserStates SyntaxAnalyzer::getCurrentState() const
{
    return currentState;
}
