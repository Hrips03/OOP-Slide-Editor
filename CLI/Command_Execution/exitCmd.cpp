#include "./includes/exitCmd.hpp"

exit::exit(const std::vector<std::string> &args) : arguments(args) {}

std::unique_ptr<ICommand> exit::clone() const
{
    return std::make_unique<exit>(*this);
}