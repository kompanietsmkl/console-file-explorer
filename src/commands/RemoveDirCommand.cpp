#include "commands/RemoveDirCommand.hpp"
#include <iostream>

void RemoveDirCommand::execute(const std::string &arg){
  if(PathUtils::is_valid_name(arg)){
    std::string choice;
    std::cout << "\\" << arg << " - all following directories and files will be removed.\nAre you willing to proceed? y/n\n";
    std::getline(std::cin, choice);

    if(choice == "y") std::filesystem::remove_all(arg);
    else if(choice == "n") return;
    else std::cerr << format::color::RED << "Invalid argument '" << choice << format::color::RESET << "\n";
  }
}