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
    std::filesystem::create_directories(dir);

    std::string filename = dir + fileName + ".bin";

    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        std::cerr << "Error: Could not open file for writing at " << filename << ".\n";
        return;
    }

    size_t slideCount = slides.size();
    ofs.write(reinterpret_cast<const char*>(&slideCount), sizeof(slideCount)); // Write slide count

    for (const auto& slide : slides) {
        size_t position = slide->getPosition();
        ofs.write(reinterpret_cast<const char*>(&position), sizeof(position)); // Write slide position

        size_t itemCount = slide->items.size();
        ofs.write(reinterpret_cast<const char*>(&itemCount), sizeof(itemCount)); // Write item count

        for (const auto& item : slide->items) {
            // Write shape type
            ofs.write(reinterpret_cast<const char*>(&item.type), sizeof(item.type));

            // Write geometric properties
            ofs.write(reinterpret_cast<const char*>(&item.geom), sizeof(item.geom));

            // Write attributes
            size_t colorLength = item.attribs.color.size();
            ofs.write(reinterpret_cast<const char*>(&colorLength), sizeof(colorLength));
            ofs.write(item.attribs.color.data(), colorLength);

            size_t outlineColorLength = item.attribs.outlineColor.size();
            ofs.write(reinterpret_cast<const char*>(&outlineColorLength), sizeof(outlineColorLength));
            ofs.write(item.attribs.outlineColor.data(), outlineColorLength);
        }
    }

    ofs.close();
    std::cout << "Document saved to " << filename << "!\n";
}


void Document::load(const std::string& fileName) {
    std::string dir = "./Saved_Files/";
    std::string filename = dir + fileName + ".bin";

    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        std::cerr << "Error: Could not open file for reading at " << filename << ".\n";
        return;
    }

    slides.clear(); // Clear existing slides

    size_t slideCount;
    ifs.read(reinterpret_cast<char*>(&slideCount), sizeof(slideCount)); // Read slide count

    for (size_t i = 0; i < slideCount; ++i) {
        size_t position;
        ifs.read(reinterpret_cast<char*>(&position), sizeof(position)); // Read slide position

        auto slide = std::make_shared<Slide>(position);

        size_t itemCount;
        ifs.read(reinterpret_cast<char*>(&itemCount), sizeof(itemCount)); // Read item count

        for (size_t j = 0; j < itemCount; ++j) {
            Item item;

            // Read shape type
            ifs.read(reinterpret_cast<char*>(&item.type), sizeof(item.type));

            // Read geometric properties
            ifs.read(reinterpret_cast<char*>(&item.geom), sizeof(item.geom));

            // Read attributes
            size_t colorLength;
            ifs.read(reinterpret_cast<char*>(&colorLength), sizeof(colorLength));
            item.attribs.color.resize(colorLength);
            ifs.read(&item.attribs.color[0], colorLength);

            size_t outlineColorLength;
            ifs.read(reinterpret_cast<char*>(&outlineColorLength), sizeof(outlineColorLength));
            item.attribs.outlineColor.resize(outlineColorLength);
            ifs.read(&item.attribs.outlineColor[0], outlineColorLength);

            slide->items.push_back(item);
        }

        slides.push_back(slide);
    }

    ifs.close();
    std::cout << "Document loaded successfully from " << filename << "!\n";
}



void Document::printHelp()
{
    std::string help = "Commands prototypes:\n"
                       "1. add slide -pos <number> : adding a slide\n"
                       "2. remove slide -pos <number> : removing a slide\n"
                       "3. print slide -pos <number> : printing a slide\n"
                       "4. add shape -type <shapeType> -x <number> -y <number> -height <number> -width <number> -slide <number> -col <colorName> -outlineColor <outlineColorName>: adding a shape\n"
                       "5. remove shape -slide <number> -shape <number> : removing a shape\n"
                       "6. change geom -slide <number> -shape <number> -<option you want to change> <number/colorName>\n"
                       "7. save -fileName <name>\n"
                       "8. load -fileName -<name>\n"
                       "9. help : displaying this help message\n"
                       "10.exit : exiting the application\n";

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
