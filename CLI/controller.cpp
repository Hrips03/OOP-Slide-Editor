#include "controller.hpp"

// senc ankax okaya?

void Controller::run(std::istream &inputStream)
{
    while (m_isRunning)
    {
        Parser obParser;
        // std::stringstream inputStringStream = getInput(inputStream);

        // if (inputStringStream.str() == "exit")
        //     break;
        //obParser.parse(inputStream);
        std::shared_ptr<ICommand> pCmd = obParser.parse(inputStream);
        //  if (pCmd)
        //  {
        //      //std::cout << "Execution...\n";
        //      pCmd->execute();
        //  }
        //  else
        //  {
        //      std::cerr << "Failed to parse command." << std::endl;
        //  }
        std::cout << "Parsing completed\n";
        break;
    }
}

void Controller::exit(){
    m_isRunning = false;
}