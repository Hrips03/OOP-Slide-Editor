#include "ICommand.hpp"

class addSlide : public ICommand
{
    int m_Position;
public:
    addSlide() : m_Position(0){}
    // addSlide(const std::map<std::string, std::variant<std::string, double>>& options) {
    //     auto it = options.find("pos");
    //     if (it != options.end() && std::holds_alternative<double>(it->second)) {
    //         m_Position = static_cast<int>(std::get<double>(it->second));  // cast double to int
    //     } else {
    //         m_Position = 0;  // Default or error value if "pos" is not present or is not a double
    //     }
    // }
    void execute() override;
    std::unique_ptr<ICommand> clone(std::map<std::string, std::variant<std::string, double>> options) override;
       
};