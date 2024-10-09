#include "parser.hpp"

int main(){
    std::string input;
    getline(std::cin, input);
    
    Parser parser(input);
    Token token;
    parser.syntaxAnalysis();
    // Get tokens one by one
    // while ((token = parser.getToken()).tokenType != Token::Type::EOC) {
    //     if (token.tokenType == Token::Type::Option) {
    //         std::cout << "Option: " << std::get<std::string>(token.value) << std::endl;
    //     } else if (token.tokenType == Token::Type::Value) {
    //         std::cout << "Value: " << std::get<int>(token.value) << std::endl;
    //     } else if (token.tokenType == Token::Type::Word) {
    //         std::cout << "Word: " << std::get<std::string>(token.value) << std::endl;
    //     }
    // }
    
}