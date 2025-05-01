#include "CommandProcessor.hpp"
#include <algorithm>

int main(){
  CommandProcessor processor;
    
  while(true){
    std::cout << std::filesystem::current_path().string() << "\n";
    std::cout << "$" << format::color::rgb::YELLOW;

    TerminalInput::setNonBlockingInput(true);
    std::string currentInput;
    char key;

    std::vector<std::string> matches;
    std::string originalInput;
    int currentMatch = -1;

    while(true){
      if(TerminalInput::isKeyPressed()){
        key = TerminalInput::getKey();

        if(key == '\t') {
          if(matches.empty() || originalInput != currentInput) {
            matches = TerminalInput::completion(currentInput);
            originalInput = currentInput;
            currentMatch = 0;
          } else {
            currentMatch = (currentMatch + 1) % matches.size();
          }
          if (!matches.empty()) {
            currentInput = matches[currentMatch];
            TerminalInput::redrawLine("$", currentInput);
          }
        }
        else if (key == '\n' || key == '\r') {
          std::cout << "\n";
          matches.clear();
          currentMatch = -1;
          break;
        }
        else if (key == 127 || key == 8) {
          if (!currentInput.empty()) {
            currentInput.pop_back();
            std::cout << "\b \b" << std::flush;
            matches.clear();
            currentMatch = -1;
          }
        }
        else if(key >= 32 && key <= 126){
          currentInput += key;
          std::cout << key << std::flush;
          matches.clear();
          currentMatch = -1;
          transform(currentInput.begin(), currentInput.end(), currentInput.begin(), ::tolower);
        }
      }
    }

    TerminalInput::setNonBlockingInput(false);
    std::cout << format::color::RESET;
    if(currentInput == "exit") break;
    processor.execute_command(currentInput);
  }
}
