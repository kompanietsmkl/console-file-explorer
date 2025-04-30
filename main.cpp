#include "CommandProcessor.hpp"

int main(){
  CommandProcessor processor;
  
  while(true){
    std::cout << std::filesystem::current_path().string() << "\n";
    std::cout << "$" << format::color::rgb::YELLOW;

    std::string input;
    std::getline(std::cin, input);
    std::cout << format::color::RESET;
    processor.execute_command(input);
  }
}
