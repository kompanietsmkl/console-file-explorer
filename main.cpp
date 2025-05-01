#include "InputProcessor.hpp"
#include "utils/TextFormat.hpp"

int main(){
  CommandProcessor processor;
    
  while(true){
    std::cout << std::filesystem::current_path().string() << "\n";
    std::cout << "$" << format::color::rgb::YELLOW;

    processInput(processor);
  }
}
