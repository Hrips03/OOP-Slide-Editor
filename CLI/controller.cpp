#include "controller.hpp"

//senc ankax okaya?
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
    m_isRunning = true;
    while (m_isRunning)
    {
        Parser obParser;
        std::stringstream inputStringStream = getInput(inputStream);
        std::shared_ptr<ICommand> pCmd;
        // stex te parserum es stugumy?
        if (!inputStringStream.str().empty())
            obParser.parse(inputStringStream);
        else
            std::cout << "No input to parse." << std::endl;
        

        // ICommand *pCmd = obParser.parse(stringStream);
        //pCmd->execute();
        break;
    }
}
