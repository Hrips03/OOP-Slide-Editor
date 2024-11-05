#include "CLI/controller.hpp"

// int main(){ 
//     Controller obj;
//     obj.run(std::cin);
// }


int main() { 
    auto controller = std::make_shared<Controller>();
    Controller::exitPtr = controller;  
    controller->run(std::cin);         
}
