#pragma once
#include <memory>
#include "CLI/controller.hpp"
#include "Editor/editor.hpp"
#include "Document/includes/document.hpp"
#include "Visualization/visualizer.hpp"

class Application
{
    Application();

    Application(const Application &) = delete;
    Application &operator=(const Application &) = delete;

    Application(const Application &&) = delete;
    Application &&operator=(const Application &&) = delete;

    static std::shared_ptr<Application> instance;

    std::shared_ptr<Controller> m_controller = nullptr;
    std::shared_ptr<Editor> m_editor = nullptr;
    std::shared_ptr<Visualizer> m_visualizer = nullptr;
    std::shared_ptr<Document> m_document = nullptr;
public:
    std::shared_ptr<Editor> getEditor();
    std::shared_ptr<Visualizer> getVisualizer();
    std::shared_ptr<Document> getDocument();
    static std::shared_ptr<Application> getInstance();
    void run();
};
