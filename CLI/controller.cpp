#include "parser.hpp"
#include "controller.hpp"

void Controller::getCommand(){
    std::string input;  //TO DO: use streams, don't know how
    std::cout << "Enter a command: ";
    getline(std::cin, input); 
    
    parser.parse(input);
}
