#include "controller.hpp"

// senc ankax okaya? - No :)
std::stringstream getInput(std::istream &inputStream)
{
    std::stringstream stringStream;
    char ch;

    //TK: Input function should not output to the console, why std::cout? 
    //TK: output formatting in a seperate task and controller should delegete all console output to it including error
    std::cout << "Enter a command: ";

    while (inputStream.get(ch))
    {
        if (ch == '\n')
            break;

        stringStream << ch;
    }

    return stringStream;
}

void Controller::run(std::istream &inputStream)
{
    while (m_isRunning)
    {
        Parser obParser;
        std::stringstream inputStringStream = getInput(inputStream);
        
        //TK: Parser & commands are skipped, not good
        //TK: exit should be a comand like other commands 
        if (inputStringStream.str() == "exit")
            break;

        std::shared_ptr<ICommand> pCmd = obParser.parse(inputStringStream);
        if (pCmd)
        {
            //std::cout << "Execution...\n";
            pCmd->execute();
        }
        else
        {
            //TK: Parser error is not implemented, there should be try catch block and parser should throw 
            //TK: see also comments above
            std::cerr << "Failed to parse command." << std::endl;
        }

        // break;
    }
}
