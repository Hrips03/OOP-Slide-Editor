#pragma once
#include <memory>
#include "CLI/controller.hpp"

class Application
{
    Application() = default;

    Application(const Application &) = delete;
    Application &operator=(const Application &) = delete;

    Application(const Application &&) = delete;
    Application &&operator=(const Application &&) = delete;

    static std::shared_ptr<Application> instance;

    std::shared_ptr<Controller> m_controller;
    std::shared_ptr<Editor> m_editor;
    std::shared_ptr<Visualizer> m_visualizer;
    std::shared_ptr<Document> m_document;
public:
    std::shared_ptr<Editor> getEditor();
    std::shared_ptr<Visualizer> getVisualizer();
    std::shared_ptr<Document> getDocument();
    static std::shared_ptr<Application> getInstance();
    void run();
};
