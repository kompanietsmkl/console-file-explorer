#include "CommandProcessor.hpp"
#include "utils/TextFormat.hpp"

bool CommandProcessor::execute_command(const std::string &input_line){
  if (input_line.empty()) {
    return true;
  }

  auto space_pos = input_line.find(' ');
  std::string command = input_line.substr(0, space_pos);

  std::string arg;
  if(space_pos != std::string::npos){
    arg = input_line.substr(space_pos + 1);
    arg.erase(0, arg.find_first_not_of(" \t"));
  }else arg = "";

  auto it = commands.find(command);

  if(it != commands.end()){
    it->second->execute(arg);
  }else{
    std::cerr << format::color::RED << command << " : The term '" << command << "' is not recognized\n" << format::color::RESET;
  }
  return true;
}