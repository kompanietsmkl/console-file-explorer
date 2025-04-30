#include "commands/ChangeDirCommand.hpp"

void ChangeDirCommand::execute(const std::string &arg){
  std::filesystem::path new_path(arg);

  if(!std::filesystem::exists(new_path)) {
    std::cerr << format::color::RED <<"Path does not exist: " << new_path << format::color::RESET << "\n"; 
    return;
  }
  if(!std::filesystem::is_directory(new_path)) {
    std::cerr << format::color::RED <<"Path is not a directory: " << new_path << format::color::RESET << "\n"; 
    return;
  }

  std::filesystem::current_path(new_path);
}