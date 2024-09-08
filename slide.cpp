#include "slide.hpp"

void Slide::add(int pos){
    assert(pos >= 0);

    //I'll use maybe list to store added slide positions, so there won't be collision    
    
    std::cout << "Slide was added succesfully at position: " << pos << "\n";
    
    slidesCount++;
    std::cout << "Slides Count: " << slidesCount << "\n";
}

void Slide::remove(size_t pos){
    //removing a slide
    slidesCount--; 
    std::cout << "Slides Count: " << slidesCount << "\n";
}
