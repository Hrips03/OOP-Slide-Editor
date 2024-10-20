#include "controller.hpp"

// senc ankax okaya?
std::stringstream getInput(std::istream &inputStream)
{
    std::stringstream stringStream;
    char ch;

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
            std::cerr << "Failed to parse command." << std::endl;
        }

        // break;
    }
}
