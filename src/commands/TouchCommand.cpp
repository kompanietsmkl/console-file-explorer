#include "commands/TouchCommand.hpp"
#include <algorithm>

void TouchCommand::execute(const std::string &arg){
  std::filesystem::path name(arg);

  if (arg.empty() || std::all_of(arg.begin(), arg.end(), isspace)) {
    std::clog << format::color::YELLOW << "Cannot create file without a name.\n" << format::color::RESET;
    return;
  }

  if (!PathUtils::is_valid_name(arg)) {
    std::cerr << format::color::RED << "Invalid file name.\n" << format::color::RESET;
    return;
  }

  if (std::filesystem::exists(name)) {
    std::cerr << format::color::RED << name << " : File with this name already exists.\n" << format::color::RESET;
    return;
  }

  std::ofstream file(arg);
  if (!file) {
    std::cerr << format::color::RED << "Failed to create file: " << name << "\n" << format::color::RESET;
    return;
  }
  file.close();
}