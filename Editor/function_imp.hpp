#include "editor.hpp"

void Editor::addSlide(Command cmd)
{
    auto it = cmd.argList.find("pos");
    int pos = static_cast<int>(std::get<double>(it->second));

    Slide newSlide;
    newSlide.ID = pos;
    std::vector<std::variant<Circle, Rect, Triangle>> shapes;

    if (pos >= 0 && pos <= doc->slides.size())
    {
        for (int i = doc->slides.size() - 1; i >= pos; --i)
        {
            auto slideIt = doc->slides.find(Slide{i});
            if (slideIt != doc->slides.end())
            {
                auto existingShapes = slideIt->second;
                doc->slides.insert({Slide{i + 1}, existingShapes});
                doc->slides.erase(slideIt);
            }
        }

        doc->slides.insert({newSlide, shapes});
        std::cout << "Slide successfully added at position " << pos << ". With ID: " << newSlide.ID << std::endl;
    }
    else
    {
        std::cout << "Cannot add at position " << pos << ". Adding slide at position " << doc->slides.size() << " instead." << std::endl;
        newSlide.ID = doc->slides.size();
        doc->slides.emplace(newSlide, shapes);
        std::cout << "Slide successfully added. With ID: " << newSlide.ID << std::endl;
    }
}

void Editor::addCircle(Command cmd)
{
    auto it1 = cmd.argList.find("pos1");
    auto it2 = cmd.argList.find("pos2");
    auto itSlide = cmd.argList.find("slide");
    auto itCol = cmd.argList.find("col");

    double pos1, pos2;
    int slideID;
    std::string color;

    pos1 = std::get<double>(it1->second);
    pos2 = std::get<double>(it2->second);
    slideID = static_cast<int>(std::get<double>(itSlide->second));

    if (itCol != cmd.argList.end() && std::holds_alternative<std::string>(itCol->second))
        color = std::get<std::string>(itCol->second);
    else
        color = "black";

    auto slideIt = std::find_if(doc->slides.begin(), doc->slides.end(),
                                [slideID](const auto &pair)
                                { return pair.first.ID == slideID; });

    if (slideIt == doc->slides.end())
    {
        std::cout << "Error: Slide with ID " << slideID << " does not exist." << std::endl;
        return;
    }

    Circle newCircle(pos1, pos2, color);
    slideIt->second.push_back(newCircle);

    std::cout << "Circle added at position (" << pos1 << ", " << pos2 << ") to slide with ID " << slideID;
    if (itCol != cmd.argList.end())
        std::cout << " with color " << color << std::endl;
    else
        std::cout << " with black color." << std::endl;
}

void Editor::addRect(Command cmd)
{
    auto it1 = cmd.argList.find("pos1");
    auto it2 = cmd.argList.find("pos2");
    auto itSlide = cmd.argList.find("slide");
    auto itCol = cmd.argList.find("col");

    double pos1, pos2;
    int slideID;
    std::string color;

    pos1 = std::get<double>(it1->second);
    pos2 = std::get<double>(it2->second);
    slideID = static_cast<int>(std::get<double>(itSlide->second));

    if (itCol != cmd.argList.end() && std::holds_alternative<std::string>(itCol->second))
        color = std::get<std::string>(itCol->second);
    else
        color = "black";

    auto slideIt = std::find_if(doc->slides.begin(), doc->slides.end(),
                                [slideID](const auto &pair)
                                { return pair.first.ID == slideID; });

    if (slideIt == doc->slides.end())
    {
        std::cout << "Error: Slide with ID " << slideID << " does not exist." << std::endl;
        return;
    }

    Rect newRect(pos1, pos2, color);
    slideIt->second.push_back(newRect);

    std::cout << "Rectangle added at position (" << pos1 << ", " << pos2 << ") to slide with ID " << slideID;
    if (itCol != cmd.argList.end())
        std::cout << " with color " << color << std::endl;
    else
        std::cout << " with black color." << std::endl;
}

void Editor::addTriangle(Command cmd)
{
    auto it1 = cmd.argList.find("pos1");
    auto it2 = cmd.argList.find("pos2");
    auto itSlide = cmd.argList.find("slide");
    auto itCol = cmd.argList.find("col");

    double pos1, pos2;
    int slideID;
    std::string color;

    pos1 = std::get<double>(it1->second);
    pos2 = std::get<double>(it2->second);
    slideID = static_cast<int>(std::get<double>(itSlide->second));

    if (itCol != cmd.argList.end() && std::holds_alternative<std::string>(itCol->second))
        color = std::get<std::string>(itCol->second);
    else
        color = "black";

    auto slideIt = std::find_if(doc->slides.begin(), doc->slides.end(),
                                [slideID](const auto &pair)
                                { return pair.first.ID == slideID; });

    if (slideIt == doc->slides.end())
    {
        std::cout << "Error: Slide with ID " << slideID << " does not exist." << std::endl;
        return;
    }

    Triangle newTriangle(pos1, pos2, color);
    slideIt->second.push_back(newTriangle);

    std::cout << "Triangle added at position (" << pos1 << ", " << pos2 << ") to slide with ID " << slideID;
    if (itCol != cmd.argList.end())
        std::cout << " with color " << color << std::endl;
    else
        std::cout << " with black color." << std::endl;
}

void Editor::remSlide(Command cmd)
{
    auto it = cmd.argList.find("pos");
    int pos = static_cast<int>(std::get<double>(it->second));

    if (pos >= 0 && pos < doc->slides.size())
    {
        Slide slideToRemove{pos};
        auto slideIt = doc->slides.find(slideToRemove);
        if (slideIt != doc->slides.end())
        {
            doc->slides.erase(slideIt);
            std::cout << "Slide at position " << pos << " successfully removed." << std::endl;

            for (int i = pos + 1; i <= doc->slides.size(); ++i)
            {
                auto nextSlideIt = doc->slides.find(Slide{i});
                if (nextSlideIt != doc->slides.end())
                {
                    auto existingShapes = nextSlideIt->second;
                    doc->slides.insert({Slide{i - 1}, existingShapes});
                    doc->slides.erase(nextSlideIt);
                }
            }
        }
        else
            std::cout << "Slide at position " << pos << " does not exist." << std::endl;
    }
    else
        std::cout << "Invalid position " << pos << ". Cannot remove slide." << std::endl;
}

void Editor::remCircle(Command cmd)
{
    auto itSlide = cmd.argList.find("slide");
    auto itPos1 = cmd.argList.find("pos1");
    auto itPos2 = cmd.argList.find("pos2");
    auto itCol = cmd.argList.find("col");

    int slideID = static_cast<int>(std::get<double>(itSlide->second));
    double pos1 = std::get<double>(itPos1->second);
    double pos2 = std::get<double>(itPos2->second);
    std::string color;

    if (itCol != cmd.argList.end() && std::holds_alternative<std::string>(itCol->second))
        color = std::get<std::string>(itCol->second);
    else
        color = "black";

    auto slideIt = std::find_if(doc->slides.begin(), doc->slides.end(),
                                [slideID](const auto &pair)
                                { return pair.first.ID == slideID; });

    if (slideIt == doc->slides.end())
    {
        std::cout << "Error: Slide with ID " << slideID << " does not exist." << std::endl;
        return;
    }

    auto &shapes = slideIt->second;
    auto circleIt = std::find_if(shapes.begin(), shapes.end(),
                                 [pos1, pos2, &color](const auto &shape)
                                 {
                                     const Circle *circlePtr = std::get_if<Circle>(&shape);
                                     return circlePtr && circlePtr->x == pos1 && circlePtr->y == pos2 &&
                                            circlePtr->color == color;
                                 });

    if (circleIt != shapes.end())
    {
        shapes.erase(circleIt);
        std::cout << "Circle at position (" << pos1 << ", " << pos2 << ") removed from slide with ID " << slideID;
        if (!color.empty())
            std::cout << " with color " << color << std::endl;
        else
            std::cout << "." << std::endl;
    }
    else
    {
        std::cout << "Error: No circle found at position (" << pos1 << ", " << pos2 << ")";
        if (!color.empty())
            std::cout << " with color " << color;
        std::cout << " on slide with ID " << slideID << std::endl;
    }
}

void Editor::remRect(Command cmd)
{
    auto itSlide = cmd.argList.find("slide");
    auto itPos1 = cmd.argList.find("pos1");
    auto itPos2 = cmd.argList.find("pos2");
    auto itCol = cmd.argList.find("col");

    int slideID = static_cast<int>(std::get<double>(itSlide->second));
    double pos1 = std::get<double>(itPos1->second);
    double pos2 = std::get<double>(itPos2->second);
    std::string color;

    if (itCol != cmd.argList.end() && std::holds_alternative<std::string>(itCol->second))
        color = std::get<std::string>(itCol->second);
    else
        color = "black";

    auto slideIt = std::find_if(doc->slides.begin(), doc->slides.end(),
                                [slideID](const auto &pair)
                                { return pair.first.ID == slideID; });

    if (slideIt == doc->slides.end())
    {
        std::cout << "Error: Slide with ID " << slideID << " does not exist." << std::endl;
        return;
    }

    auto &shapes = slideIt->second;
    auto RectIt = std::find_if(shapes.begin(), shapes.end(),
                               [pos1, pos2, &color](const auto &shape)
                               {
                                   const Rect *RectPtr = std::get_if<Rect>(&shape);
                                   return RectPtr && RectPtr->x == pos1 && RectPtr->y == pos2 &&
                                          RectPtr->color == color;
                               });

    if (RectIt != shapes.end())
    {
        shapes.erase(RectIt);
        std::cout << "Rectangle at position (" << pos1 << ", " << pos2 << ") removed from slide with ID " << slideID;
        if (!color.empty())
            std::cout << " with color " << color << std::endl;
        else
            std::cout << "." << std::endl;
    }
    else
    {
        std::cout << "Error: No rectangle found at position (" << pos1 << ", " << pos2 << ")";
        if (!color.empty())
            std::cout << " with color " << color;
        std::cout << " on slide with ID " << slideID << std::endl;
    }
}

void Editor::remTriangle(Command cmd)
{
    auto itSlide = cmd.argList.find("slide");
    auto itPos1 = cmd.argList.find("pos1");
    auto itPos2 = cmd.argList.find("pos2");
    auto itCol = cmd.argList.find("col");

    int slideID = static_cast<int>(std::get<double>(itSlide->second));
    double pos1 = std::get<double>(itPos1->second);
    double pos2 = std::get<double>(itPos2->second);
    std::string color;

    if (itCol != cmd.argList.end() && std::holds_alternative<std::string>(itCol->second))
        color = std::get<std::string>(itCol->second);
    else
        color = "black";

    auto slideIt = std::find_if(doc->slides.begin(), doc->slides.end(),
                                [slideID](const auto &pair)
                                { return pair.first.ID == slideID; });

    if (slideIt == doc->slides.end())
    {
        std::cout << "Error: Slide with ID " << slideID << " does not exist." << std::endl;
        return;
    }

    auto &shapes = slideIt->second;
    auto TriangleIt = std::find_if(shapes.begin(), shapes.end(),
                                   [pos1, pos2, &color](const auto &shape)
                                   {
                                       const Triangle *TrianglePtr = std::get_if<Triangle>(&shape);
                                       return TrianglePtr && TrianglePtr->x == pos1 && TrianglePtr->y == pos2 &&
                                              TrianglePtr->color == color;
                                   });

    if (TriangleIt != shapes.end())
    {
        shapes.erase(TriangleIt);
        std::cout << "Triangle at position (" << pos1 << ", " << pos2 << ") removed from slide with ID " << slideID;
        if (!color.empty())
            std::cout << " with color " << color << std::endl;
        else
            std::cout << "." << std::endl;
    }
    else
    {
        std::cout << "Error: No triangle found at position (" << pos1 << ", " << pos2 << ")";
        if (!color.empty())
            std::cout << " with color " << color;
        std::cout << " on slide with ID " << slideID << std::endl;
    }
}

void Editor::printHelp()
{
    doc->help += "Commands prototypes:\n"
                 "add slide -pos <number> : adding a slide\n"
                 "remove slide -pos <number> : removing a slide\n"
                 "print slide -pos <number> : printing a slide\n"
                 "add circle -pos1 <number> -pos2 <number> -slide <number> -col <colorName> : adding a circle (color is optional)\n"
                 "remove circle -pos1 <number> -pos2 <number> -slide <number> -col <colorName> : removing a circle (color is optional)\n"
                 "add rect -pos1 <number> -pos2 <number> -slide <number> -col <colorName>: adding a rectangle (color is optional)\n"
                 "remove rect -pos1 <number> -pos2 <number> -slide <number> -col <colorName>: removing a rectangle (color is optional)\n"
                 "add triangle -pos1 <number> -pos2 <number> -slide <number> -col <colorName>: adding a triangle (color is optional)\n"
                 "remove triangle -pos1 <number> -pos2 <number> -slide <number> -col <colorName>: removing a triangle (color is optional)\n"
                 "print slides : printing all slides\n"
                 "help : displaying this help message\n"
                 "exit : exiting the application";
    std::cout << doc->help << std::endl;
}

void Editor::printSlide(Command cmd)
{
    auto it = cmd.argList.find("pos");
    int pos = static_cast<int>(std::get<double>(it->second));

    if (pos < 0 || pos >= doc->slides.size())
    {
        std::cout << "Error: Invalid position " << pos << ". Cannot remove slide." << std::endl;
        return;
    }

    auto slideIt = doc->slides.begin();
    std::advance(slideIt, pos);

    Visualizer visual;
    visual.printSlide(std::cout, slideIt);
}

void Editor::printSlides()
{
    if (doc->slides.size() > 0)
    {
        Visualizer visual;
        visual.printSlides(std::cout, doc->slides);
    }
    else
        std::cout << "There are no slides to be printed\n";
}