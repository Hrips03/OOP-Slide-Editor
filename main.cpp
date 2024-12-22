#include "Application.hpp"

int main() { 
    std::shared_ptr<Application> app = Application::getInstance();
    app->run();        
}
