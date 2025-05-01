#include "CommandProcessor.hpp"

int main(){
  CommandProcessor processor;
    
  while(true){
    std::cout << std::filesystem::current_path().string() << "\n";
    std::cout << "$" << format::color::rgb::YELLOW;

    TerminalInput::setNonBlockingInput(true);
    std::string currentInput;
    char key;

    while(true){

      if(TerminalInput::isKeyPressed()){
        key = TerminalInput::getKey();

        if(key == '\t'){
          auto matches = TerminalInput::completion(currentInput);
          if(!matches.empty()){
            for(const auto &match: matches){
              currentInput = match;
              TerminalInput::redrawLine("$", match);
            }
          }
        }
        else if(key == '\n' || key == '\r'){
          std::cout << "\n";
          break;
        }
        else if (key == 127 || key == 8) {
          if (!currentInput.empty()) {
            currentInput.pop_back();
            std::cout << "\b \b" << std::flush;
          }
        }
        else if(key >= 32 && key <= 126){
          currentInput += key;
          std::cout << key << std::flush;
        }
      }
    }

    TerminalInput::setNonBlockingInput(false);
    std::cout << format::color::RESET;
    processor.execute_command(currentInput);
  }
}
