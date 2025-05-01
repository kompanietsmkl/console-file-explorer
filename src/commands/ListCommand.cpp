#include "commands/ListCommand.hpp"
#include "utils/FileClock.hpp"
#include "utils/FilePermissions.hpp"
#include <iostream>

std::string ListCommand::wo_quotes(const std::filesystem::path &path){
  std::string curr = path.filename().string();

  if(curr.front() == '"'){
    curr.erase(0, 1);
  }
  if(curr.back() == '"'){
    curr.pop_back();
  }

  return curr;
}

void ListCommand::execute(const std::string &arg){
  auto path = std::filesystem::current_path();

  std::cout << "\tDirectory: "<< path.string() << "\n\n"
  << std::setw(10) << std::left << "Mode"
  << std::setw(25) << std::right << "\tLastWriteTime"
  << std::setw(13) << std::right << "Length "
  << std::setw(15) << std::left << "Name" << "\n";

  for(auto &entry: std::filesystem::directory_iterator(path)){
    std::cout << std::setw(12) << std::left << FileUtils::print_permissions(entry)
    << std::setw(25) << std::right << Time::time(entry)
    << std::setw(12) << std::right << ((!std::filesystem::is_directory(entry)) ? std::to_string(std::filesystem::file_size(entry)) : "") << " "
    << std::setw(15) << std::left << wo_quotes(entry) << "\n";
  }
}