#include "parser.hpp"
#include "controller.hpp"

void Controller::getCommand(){
    //TO DO: use streams, don't know how
    std::cout << "Enter a command: ";
    getline(std::cin, input); 
}


void Controller::parse(){
    parser.parse(input);
}