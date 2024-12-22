#include "includes/document.hpp"

std::vector<std::shared_ptr<Slide>> Document::slides;

void Document::addSlide(std::shared_ptr<Slide> slide)
{
    int position = slide->getPosition();
    slides.insert(slides.begin() + position, slide);
    std::cout << "Slide is succesfully added at position " << position << ".\n"
              << std::endl;
}

void Document::remSlide(int position)
{
    if (position >= 0 && position < static_cast<int>(slides.size()))
    {
        slides.erase(slides.begin() + position);
        std::cout << "Slide is succesfully removed from position " << position << ".\n"
                  << std::endl;
    }
    else
        std::cerr << "Error: Position " << position << " is out of bounds.\n"
                  << std::endl;
}

void Document::addShape(int slideNumber, std::shared_ptr<Item> item)
{
    if (slideNumber < 0 || slideNumber >= slides.size())
    {
        std::cerr << "Invalid slide number.\n"
                  << std::endl;
        return;
    }
    else
    {
        Item shape;
        shape.type = item->type;
        shape.geom = item->geom;
        shape.attribs = item->attribs;
        slides[slideNumber]->items.push_back(shape);
        std::cout << "Shape added to slide " << slideNumber << " successfully.\n"
                  << std::endl;
    }
}

void Document::remShape(int slideNumber, int itemNumber)
{
    if (slideNumber < 0 || slideNumber >= slides.size())
    {
        std::cerr << "Invalid slide number.\n"
                  << std::endl;
        return;
    }
    else
    {
        auto &shapes = slides[slideNumber]->items;
        shapes.erase(shapes.begin() + itemNumber);
        std::cout << "Shape removed from slide " << slideNumber << " successfully.\n"
                  << std::endl;
    }
}

void Document::changeGeom(int slideNum, int itemNum, Item::Geometry itemGeom, Item::Attributes itemAttribs)
{
    auto &shape = slides[slideNum]->items[itemNum];
    if (shape.geom.x != itemGeom.x)
        shape.geom.x = itemGeom.x;
    else if (shape.geom.y != itemGeom.y)
        shape.geom.y = itemGeom.y;
    else if (shape.geom.height != itemGeom.height)
        shape.geom.height = itemGeom.height;
    else if (shape.geom.width != itemGeom.width)
        shape.geom.width = itemGeom.width;

    if (shape.attribs.color != itemAttribs.color)
        shape.attribs.color = itemAttribs.color;
    else if (shape.attribs.outlineColor != itemAttribs.outlineColor)
        shape.attribs.outlineColor = itemAttribs.outlineColor;

    std::cout << "Shape's geometry changed successfully.\n"
              << std::endl;
}

void Document::save(const std::string& fileName) {
    std::string dir = "./Saved_Files/";
    std::filesystem::create_directories(dir); // Ensure the directory exists

    std::string filename = dir + fileName + ".txt";

    std::ofstream file(filename, std::ios::out); // Use std::ios::out for normal writing

    if (file.is_open()) {
        size_t slideIndex = 0; // Start from Slide 0
        Visualizer visualizer;

        for (const auto& slide : slides) {
            visualizer.printSlide(file, slide, slideIndex++); // Save slides using the updated format
        }

        file.close();
        std::cout << "Document saved to " << filename << "!\n";
    } else {
        std::cerr << "Error: Could not open file for writing at " << filename << ".\n";
    }
}

void Document::load(const std::string& fileName) {
    std::string dir = "./Saved_Files/";
    std::string filename = dir + fileName + ".txt";

    std::ifstream file(filename, std::ios::in);

    if (file.is_open()) {
        slides.clear(); // Clear existing slides
        std::shared_ptr<Slide> currentSlide = nullptr;

        std::string line;
        while (std::getline(file, line)) {
            if (line.find("Slide") == 0) { // Start of a new slide
                size_t position = slides.size(); // Determine position for the new slide
                currentSlide = std::make_shared<Slide>(position);
                slides.push_back(currentSlide);
            } else if (line.find("  Shape") == 0 && currentSlide != nullptr) {
                Item shape;
                std::istringstream iss(line);

                std::string temp;
                char colon;

                // Parse shape type
                iss >> temp >> temp >> colon; // Skip "Shape <index>:"
                if (temp == "Ellipse") shape.type = Item::ShapeType::Ellipse;
                else if (temp == "Rectangle") shape.type = Item::ShapeType::Rectangle;
                else if (temp == "Triangle") shape.type = Item::ShapeType::Triangle;

                // Parse shape attributes
                while (iss >> temp) {
                    if (temp == "X:") iss >> shape.geom.x;
                    else if (temp == "Y:") iss >> shape.geom.y;
                    else if (temp == "Height:") iss >> shape.geom.height;
                    else if (temp == "Width:") iss >> shape.geom.width;
                    else if (temp == "Color:") iss >> shape.attribs.color;
                    else if (temp == "Outline") {
                        iss >> temp; // Skip "Color:"
                        iss >> shape.attribs.outlineColor;
                    }
                }

                // Add the parsed shape to the current slide
                currentSlide->items.push_back(shape);
            }
        }

        file.close();
        std::cout << "Document loaded successfully from " << filename << "!\n";
    } else {
        std::cerr << "Error: Could not open file for reading at " << filename << ".\n";
    }
}


void Document::printHelp()
{
    std::string help = "Commands prototypes:\n"
                       "add slide -pos <number> : adding a slide\n"
                       "remove slide -pos <number> : removing a slide\n"
                       "print slide -pos <number> : printing a slide\n"
                       "add shape -type <shapeType> -x <number> -y <number> -height <number> -width <number> -slide <number> -col <colorName> -outlineColor <outlineColorName>: adding a shape (color is optional)\n"
                       "remove shape -type <shapeType> -x <number> -y <number> -height <number> -width <number> -slide <number> -col <colorName> -outlineColor <outlineColorName> : removing a shape (color is optional)\n"
                       "help : displaying this help message\n"
                       "exit : exiting the application\n";

    std::cout << help << std::endl;
}

void Document::printSlide(int pos)
{
    if (pos < 0 || pos >= slides.size())
    {
        std::cout << "Error: Invalid position " << pos << ". Cannot remove slide.\n"
                  << std::endl;
        return;
    }

    auto slideIt = slides.begin();
    std::advance(slideIt, pos);

    Visualizer visual;
    visual.printSlide(std::cout, *slideIt, pos);
}

void Document::printSlides()
{
    if (slides.size() > 0)
    {
        Visualizer visual;
        visual.printSlides(std::cout, slides);
    }
    else
    {
        std::cout << "There are no slides to be printed\n"
                  << std::endl;
    }
}
