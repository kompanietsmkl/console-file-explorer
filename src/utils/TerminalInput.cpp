#include "utils/TerminalInput.hpp"
#include <iostream>

namespace TerminalInput{
  NonBlockingGuard::NonBlockingGuard() { setNonBlockingInput(true); }
  NonBlockingGuard::~NonBlockingGuard() { setNonBlockingInput(false); }

  static const std::deque<std::string> commands{
    "cd", "clear", "dir", "ls", "mkdir", 
    "pwd", "rmdir", "touch", "exit"
  };
  
  std::vector<std::string> completion(const std::string &cmd){
    std::vector<std::string> matches;
    if(cmd.empty()) return matches;

    for(const auto &command: commands){
      if(command.substr(0, cmd.size()) == cmd){
        matches.push_back(command);
      }
    }
    return matches;
  }
  
  void redrawLine(const std::string &prompt, const std::string &input){
    std::cout << "\r";
    std::cout << prompt << input;
    std::cout << std::string(50, ' ');
    std::cout << "\r" << prompt << input << std::flush;
  }

  void setNonBlockingInput(bool enable){
    #ifdef _WIN32
    #else
      static struct termios oldt, newt;
      if (enable) {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      }
    #endif
  }
  
  bool isKeyPressed(){
    #ifdef _WIN32
      return _kbhit() != 0;
    #else
      struct timeval tv = {0, 0};
      fd_set fds;
      FD_ZERO(&fds);
      FD_SET(STDIN_FILENO, &fds);
      return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0;
    #endif
  }
  
  char getKey(){
    #ifdef _WIN32
      return _getch();
    #else
      char ch = 0;
      read(STDIN_FILENO, &ch, 1);
      return ch;
    #endif
  }

}
