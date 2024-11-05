#include "syntaxAnalyzer.hpp"

Command SyntaxAnalyzer::processInput(Token input)
{
    static std::string currentOption;
    static bool expectingValue = false;

    switch (currentState)
    {
    case ParserStates::Start:
        switch (input.tokenType)
        {
        case Token::Type::Word:
            currentState = ParserStates::Command;
            m_cmd.cmdName = std::get<std::string>(input.value);
            break;
        case Token::Type::Unknown:
            currentState = ParserStates::Error;
            throw std::invalid_argument("Unknown symbol: Only alfa-numeric symbols are allowed.");
            break;
        case Token::Type::Option:
        case Token::Type::Value:
        case Token::Type::EOC:
            currentState = ParserStates::Error;
            throw std::invalid_argument("Commmand name should consit of only letters.");
            break;
        }

        break;

    case ParserStates::Command:
        switch (input.tokenType)
        {
        case Token::Type::Word:
            m_cmd.cmdName += " " + std::get<std::string>(input.value);
            currentState = ParserStates::Command;
            break;
        case Token::Type::Option:
            currentOption = std::get<std::string>(input.value);
            m_cmd.argList[currentOption];
            expectingValue = true;
            currentState = ParserStates::Argument;
            break;
        case Token::Type::EOC:
            currentState = ParserStates::Finish;
            break;
        case Token::Type::Unknown:
            currentState = ParserStates::Error;
            throw std::invalid_argument("Unknown symbol: Only alfa-numeric symbols are allowed.");
            break;
        case Token::Type::Value:
            currentState = ParserStates::Error;
            throw std::invalid_argument("Expecting an option, not a value.");
            break;
        }
        break;

    case ParserStates::Argument:
        switch (input.tokenType)
        {
        case Token::Type::Option:
            if (expectingValue)
            {
                currentState = ParserStates::Error;
                throw std::invalid_argument("Missing required value for option: " + currentOption);
            }
            currentState = ParserStates::Argument;
            currentOption = std::get<std::string>(input.value);
            m_cmd.argList[currentOption];
            expectingValue = true;
            break;
        case Token::Type::Value:
            if (expectingValue)
            {
                if (auto doublePtr = std::get_if<double>(&input.value))
                    m_cmd.argList[currentOption] = *doublePtr;
                else if (auto stringPtr = std::get_if<std::string>(&input.value))
                    m_cmd.argList[currentOption] = *stringPtr;
                expectingValue = false;
            }
            else
            {
                currentState = ParserStates::Error;
                throw std::invalid_argument("Unexpected value without option.");
            }
            currentState = ParserStates::Argument;
            break;
        case Token::Type::EOC:
            if (expectingValue)
            {
                currentState = ParserStates::Error;
                throw std::invalid_argument("Missing required value for option: " + currentOption);
            }
            currentState = ParserStates::Finish;
            break;
        case Token::Type::Unknown:
            currentState = ParserStates::Error;
            throw std::invalid_argument("Unknown symbol: Only alfa-numeric symbols are allowed.");
            break;
        case Token::Type::Word:
            currentState = ParserStates::Error;
            throw std::invalid_argument("Expecting an end of line or another option-value pair.");
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
