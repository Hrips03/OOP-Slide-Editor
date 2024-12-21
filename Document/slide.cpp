#include "./includes/slide.hpp"

Slide::Slide(int position) : m_pos(position) {}

int Slide::getPosition() const
{
    return m_pos;
}

void Slide::setPosition(int pos) 
{
    m_pos = pos;
}
