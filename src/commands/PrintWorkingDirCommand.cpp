#include "commands/PrintWorkingDirCommand.hpp"
#include <iostream>
#include <filesystem>

void PrintWorkingDirCommand::execute(const std::string &arg) {
  auto path = std::filesystem::current_path().string();

  #ifdef _WIN32
    std::cout <<"Path \n----\n" << path << "\n\n\n";
  #elif __linux__ 
    auto target = path.rfind('\\');
    std::cout << path.substr(target)<< "\n";
  #elif __APPLE__
  #endif
}