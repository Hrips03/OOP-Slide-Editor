#include "syntaxAnalyzer.hpp"

Command SyntaxAnalyzer::processInput(Token input)
{
    static std::string currentOption; // Holds the current option name temporarily
    static Command cmd;

    switch (currentState)
    {
    case ParserStates::Start:
        switch (input.tokenType)
        {
        case Token::Type::Word:
            currentState = ParserStates::Command;
            cmd.cmdName = std::get<std::string>(input.value); 
            break;
        default:
            currentState = ParserStates::Error;
            break;
        }
        break;

    case ParserStates::Command:
        switch (input.tokenType)
        {
        case Token::Type::Option:
            currentState = ParserStates::Argument;
            currentOption = std::get<std::string>(input.value); 
            break;
        case Token::Type::Word:
            cmd.cmdName += " " + std::get<std::string>(input.value); 
            break;
        case Token::Type::EOC:
            currentState = ParserStates::Finish;
            break;
        default:
            currentState = ParserStates::Error;
            break;
        }
        break;

    case ParserStates::Argument:
        switch (input.tokenType)
        {
        case Token::Type::Value:
            cmd.argList[currentOption] = std::get<double>(input.value);
            currentState = ParserStates::Command; 
            break;
        case Token::Type::EOC:
            currentState = ParserStates::Finish;
            break;
        default:
            currentState = ParserStates::Error;
            break;
        }
        break;

    // case ParserStates::Finish:
    //     // Command processing is complete; handle finalization if needed
    //     break;

    // case ParserStates::Error:
    //     // Handle error logging or cleanup if necessary
    //     break;
    }
    

    printCurrentState();
    return cmd;
}



void SyntaxAnalyzer::printCurrentState()
{
    std::cout << "Current State: ";
    switch (currentState)
    {
    case ParserStates::Start:
        std::cout << "Start";
        break;
    case ParserStates::Command:
        std::cout << "Command";
        break;
    case ParserStates::Argument:
        std::cout << "Argument";
        break;
    case ParserStates::Finish:
        std::cout << "Finish";
        break;
    case ParserStates::Error:
        std::cout << "Error";
        break;
    }
    std::cout << std::endl;
}

ParserStates SyntaxAnalyzer::getCurrentState() const
{
    return currentState;
}

void SyntaxAnalyzer::reset()
{
    currentState = ParserStates::Start; 
}