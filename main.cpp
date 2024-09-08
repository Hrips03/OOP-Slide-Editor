#include "slide.hpp"
#include "parser.hpp"

int main(int argc, char *argv[]) {
    Slide s;
    s.add(0); 
    s.add(7); 
    s.add(0); 
    //s.add(-1); 
    
    std::cout << argc << std::endl;
    for (size_t i = 0; i < argc; i++)
        std::cout << "argv[" << i <<"] = " << argv[i] << "\n";
    
    Parser p(argv);
    
    //s.remove(0);  
    return 0;
}
