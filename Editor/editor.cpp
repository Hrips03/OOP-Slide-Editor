#include "editor.hpp"

void Editor::handler(Command cmd)
{
    if (cmd.cmdName == "add slide")
    {
        auto it = cmd.argList.find("pos");
        int pos = static_cast<int>(std::get<double>(it->second));
        Slide newSlide;

        std::cout << "doc->slides.size() befor adding = " << doc->slides.size() << std::endl;

        if (pos >= 0 && pos <= doc->slides.size())
        {
            doc->slides.insert(doc->slides.begin() + pos, newSlide);
        }
        else
        {
            std::cout << "Cannot add at position " << pos << ". Adding at the end instead." << std::endl;
            doc->slides.emplace_back(newSlide);
        }
        std::cout << "doc->slides.size() after adding = " << doc->slides.size() << std::endl;
    }
    else if (cmd.cmdName == "remove slide")
    {
        std::cout << "Handling remove slide command's execution...\n";
        std::cout << "doc->slides.size() before removing = " << doc->slides.size() << std::endl;
        auto it = cmd.argList.find("pos");
        int pos = static_cast<int>(std::get<double>(it->second));

        if (pos >= 0 && pos < doc->slides.size())
        {
            doc->slides.erase(doc->slides.begin() + pos);
            std::cout << "Slide removed from position " << pos << ".\n";
        }
        else
        {
            std::cout << "Invalid position: " << pos << ". No slide removed.\n";
        }
        std::cout << "doc->slides.size() after removing = " << doc->slides.size() << std::endl;

    }
    else if (cmd.cmdName == "print slide")
    {
        std::cout << "Handling print slide command's execution...\n";
    }
    else if (cmd.cmdName == "add circle")
    {
        std::cout << "Handling add circle command's execution...\n";
    }
    else if (cmd.cmdName == "remove circle")
    {
        std::cout << "Handling remove circle command's execution...\n";
    }
    else if (cmd.cmdName == "add rect")
    {
        std::cout << "Handling add rect command's execution...\n";
    }
    else if (cmd.cmdName == "remove rect")
    {
        std::cout << "Handling remove rect command's execution...\n";
    }
    else if (cmd.cmdName == "add triangle")
    {
        std::cout << "Handling add triangle command's execution...\n";
    }
    else if (cmd.cmdName == "remove triangle")
    {
        std::cout << "Handling remove triangle command's execution...\n";
    }
    else if (cmd.cmdName == "print slides")
    {
        std::cout << "Handling print slides command's execution...\n";
    }
    else if (cmd.cmdName == "help")
    {
        doc->help += "Commands prototypes:\n add slide -pos <number> : adding a slide";
        std::cout << "Handling add help command's execution...\n";
    }
    else if (cmd.cmdName == "exit")
    {
        // exit.contorller.lock()->m_isRunning = false;

        std::cout << "Handling add exit command's execution...\n";
    }
}
