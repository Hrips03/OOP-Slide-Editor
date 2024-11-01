#include "./includes/helpCmd.hpp"

help::help(const std::vector<std::string> &args) : arguments(args) {}

std::unique_ptr<ICommand> help::clone() const
{
    return std::make_unique<help>(*this);
}