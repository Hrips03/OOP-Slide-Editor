#pragma once

class Slide {
public:
    int ID;
    // Slide();
    // Slide(const Slide &other) : ID(other.ID){}
    Slide &operator=(const Slide &other);
    bool operator<(const Slide& other) const;
};