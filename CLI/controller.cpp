#include "parser.hpp"
#include "controller.hpp"

void Controller::getCommand(){
    std::string input;  //TO DO: change to stream object
    std::cout << "Enter a command: ";
    getline(std::cin, input);
    
    parser.parse(input);
}
