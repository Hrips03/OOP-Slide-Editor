#include "slide.hpp"
#include "parser.hpp"

int main(int argc, char *argv[]) {
    // Slide s;
    // s.add(0); 
    // s.add(7); 
    // s.add(0); 
    //s.add(-1); 
    
    if(argc >= 1) 
        Parser p(argc, argv);
    
    //s.remove(0);  
    return 0;
}
