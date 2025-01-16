#include "Application.hpp"
 
std::shared_ptr<Application> Application::getInstance()
{
    if (!Application::instance)
    {
        Application::instance = std::shared_ptr<Application>(new Application());
    }
    return Application::instance;
}

Application::Application()
{
    m_editor = std::make_shared<Editor>();
    m_visualizer = std::make_shared<Visualizer>();
    m_controller = std::make_shared<Controller>();
    m_document = std::make_shared<Document>();
    Controller::exitPtr = m_controller;
}

std::shared_ptr<Application> Application::instance = nullptr;

void Application::run()
{

    m_controller->run(std::cin);
}

std::shared_ptr<Editor> Application::getEditor()
{
    return m_editor;
}

std::shared_ptr<Visualizer> Application::getVisualizer()
{
    return m_visualizer;
}

std::shared_ptr<Document> Application::getDocument()
{
    return m_document;
}
