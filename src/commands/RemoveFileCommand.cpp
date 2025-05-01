#include "commands/RemoveFileCommand.hpp"
#include "utils/TextFormat.hpp"
#include "utils/NameValidation.hpp"
#include <algorithm>
#include <iostream>
#include <filesystem>

void RemoveFileCommand::execute(const std::string &arg){
  std::filesystem::path path(arg);

  if (arg.empty() || std::all_of(arg.begin(), arg.end(), isspace)) {
    std::clog << format::color::YELLOW << "Cannot remove file without a name.\n" << format::color::RESET;
    return;
  }

  if (!PathUtils::is_valid_name(arg)) {
    std::cerr << format::color::RED << "Invalid file name.\n" << format::color::RESET;
    return;
  }

  if (!std::filesystem::exists(path)) {
    std::cerr << format::color::RED << path << ": No instance of file is found in the directory.\n" << format::color::RESET;
    return;
  }

  if (!std::filesystem::remove(path)) {
    std::cerr << format::color::RED << "Failed to remove file.\n" << format::color::RESET;
    return;
  }
}