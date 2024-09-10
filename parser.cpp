#include "parser.hpp"

Parser::Parser(int argc, char *argv[]) : argc{argc}
{
    for (int i = 0; i < argc; i++)
        this->argv.push_back(std::string(argv[i]));

    std::cout << "Parser is created!\n";

    //here?
    printCLI();

    if (argc >= 2 && this->argv[1] != "--help" && this->argv[1] != "-h")
        validateInput();    
}

void Parser::printCLI()
{
    std::cout << "argc = " << argc << std::endl;
    for (size_t i = 0; i < argc; i++)
        std::cout << "argv[" << i << "] = " << argv[i] << "\n";


    if (argc == 1)
        std::cout << "Usage: Provide a specific command.(See --help if you don't know how)\n";
    else if (argc > 1 && (argv[1] == "--help" || argv[1] == "-h"))
    {
        std::cout << "Options:\n";
        std::cout << "  --add slide/shape/textbox/image <position>        Add a slide, shape, textbox, or image at a given position.\n";
        std::cout << "  --remove slide/shape/textbox/image <position>     Remove a slide, shape, textbox, or image from a given position.\n";
        std::cout << "  -h, --help                                        Display this help menu.\n";
    }


    // Controller or Parser??
    //  if(argv[1] == "--add" && argv[2] == "slide")
    //      Slide::add(argv[3]);
}

void Parser::validateInput()
{
    if (argv[1] == "--add" || argv[1] == "--remove")
    {
        if (argc > 2)
        {
            if (argv[2] == "slide" || argv[2] == "shape" || argv[2] == "textbox" || argv[2] == "image")
            {
                if (argc > 3)
                {
                    int pos = 0;
                    try
                    {
                        pos = std::stoi(argv[3]);
                    }
                    catch (const std::invalid_argument &e)
                    {
                        std::cout << "Invalid input: Last input has to be an integer." << std::endl;
                        return;
                    }

                    if (pos > 0)
                        //logic will be written
                        std::cout << "Adding/Removing " << argv[2] << " at position " << pos << ".\n"; 
                    else
                        std::cout << "Position must be greater than zero.\n";
                    
                }
                else
                    std::cout << "Not enough arguments! See --help.\n";
            }
            else
                std::cout << "Command is not valid! See --help.\n";
        }
        else
            std::cout << "Not enough arguments! See --help.\n";
    }
    else
        std::cout << "Command is not valid! See --help.\n";
}