#pragma once
#include <memory>

class Application
{
    Application() = default;

    Application(const Application &) = delete;
    Application &operator=(const Application &) = delete;

    Application(const Application &&) = delete;
    Application &&operator=(const Application &&) = delete;

    static std::shared_ptr<Application> instance;

public:
    static std::shared_ptr<Application> getInstance();
    void run();
};
