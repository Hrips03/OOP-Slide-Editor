#include "Application.hpp"
#include "CLI/controller.hpp"
#include <iostream>


std::shared_ptr<Application> Application::getInstance()
{
    if (!Application::instance)
    {
        Application::instance = std::shared_ptr<Application>(new Application());
    }
    return Application::instance;
}

std::shared_ptr<Application> Application::instance = nullptr;

void Application::run() {
    auto controller = std::make_shared<Controller>();
    Controller::exitPtr = controller;  
    controller->run(std::cin);
}
