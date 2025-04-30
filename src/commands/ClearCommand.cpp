#include "commands/ClearCommand.hpp"

void ClearCommand::execute(const std::string &arg){
  #ifdef _WIN32 
    system("cls");
  #elif __linux__ 
    system("clear");
  #elif __APPLE__ 
    system("clear");
  #endif
}