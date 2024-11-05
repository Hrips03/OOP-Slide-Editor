#include "controller.hpp"
#include "./Command_Execution/includes/exitCmd.hpp"

std::shared_ptr<Controller> Controller::exitPtr = nullptr;

void Controller::run(std::istream &inputStream)
{
    //exitCmd(std::make_shared<Controller>(*this));

    while (m_isRunning)
    {
        Parser obParser;
        std::shared_ptr<ICommand> pCmd = obParser.parse(inputStream);
        if (pCmd)
            pCmd->execute();
        else
            std::cerr << "Failed to parse command.\n" << std::endl;
    }
}

void Controller::exit(){
    m_isRunning = false;
}

