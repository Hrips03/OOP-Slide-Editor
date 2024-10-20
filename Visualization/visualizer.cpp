#include "visualizer.hpp"

void Visualizer::printSlide(std::ostream &out, std::map<Slide, std::vector<std::variant<Circle, Rect, Triangle>>>::iterator slideIt)
{
    out << "Slide: " << slideIt->first.ID << std::endl;

    const auto &shapes = slideIt->second;
    for (const auto &shape : shapes)
    {
        std::visit([&out](const auto &s)
                   { s.print(out); }, shape);
    }
}

void Visualizer::printSlides(std::ostream &out, std::map<Slide, std::vector<std::variant<Circle, Rect, Triangle>>> slides)
{
    for (auto slideIt = slides.begin(); slideIt != slides.end(); slideIt++)
    {
        out << "Slide: " << slideIt->first.ID << std::endl;

        const auto &shapes = slideIt->second;
        for (const auto &shape : shapes)
        {
            std::visit([&out](const auto &s)
                       { s.print(out); }, shape);
        }
    }
}
