#include "syntaxAnalyzer.hpp"

Command SyntaxAnalyzer::processInput(Token input)
{
    static std::string currentOption;

    switch (currentState)
    {
    case ParserStates::Start:
        if (input.tokenType == Token::Type::Word)
        {
            currentState = ParserStates::Command;
            m_cmd.cmdName = std::get<std::string>(input.value);
        }
        else
        {
            currentState = ParserStates::Error;
        }
        break;

    case ParserStates::Command:
        switch (input.tokenType)
        {
        case Token::Type::Word:
            m_cmd.cmdName += " " + std::get<std::string>(input.value);
            break;
        case Token::Type::Option:
            currentOption = std::get<std::string>(input.value);
            m_cmd.argList[currentOption]; 
            currentState = ParserStates::Argument;
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
        case Token::Type::Option:
            currentOption = std::get<std::string>(input.value);
            m_cmd.argList[currentOption]; 
            break;
        case Token::Type::Value:
            if (auto doublePtr = std::get_if<double>(&input.value))
                m_cmd.argList[currentOption] = *doublePtr; 
            else if (auto stringPtr = std::get_if<std::string>(&input.value))
                m_cmd.argList[currentOption] = *stringPtr; 
            break;
        case Token::Type::EOC:
            currentState = ParserStates::Finish;
            break;
        default:
            currentState = ParserStates::Error;
            break;
        }
        break;
    }

    //printCurrentState();
    return m_cmd;
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