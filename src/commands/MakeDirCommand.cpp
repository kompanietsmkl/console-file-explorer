#include "commands/MakeDirCommand.hpp"
#include "utils/FilePermissions.hpp"
#include "utils/NameValidation.hpp"
#include "utils/TextFormat.hpp"
#include <iostream>
#include <filesystem>

void MakeDirCommand::execute(const std::string &arg){
  auto path = std::filesystem::current_path().string();
  if(PathUtils::is_valid_name(arg)){
    try {
      std::filesystem::create_directories(arg);
    } catch (const std::filesystem::filesystem_error& e) {
      std::cerr << format::color::RED <<"Error creating directory: " << e.what() << format::color::RESET << "\n";
    }
  } else std::cerr << format::color::RED << arg << " : Invalid directory name.\n" << format::color::RESET;
}