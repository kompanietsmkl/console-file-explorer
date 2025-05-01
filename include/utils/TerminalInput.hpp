#pragma once
#include <deque>
#include <string>
#include <vector>

#ifdef _WIN32
  #include <conio.h>
#else
  #include <termios.h>
  #include <unistd.h>
  #include <fcntl.h>
#endif

namespace TerminalInput{
  class NonBlockingGuard {
  public:
    NonBlockingGuard();
    ~NonBlockingGuard();
  };

  std::vector<std::string> completion(const std::string &);

  void setNonBlockingInput(bool enable);
  bool isKeyPressed();
  char getKey();
  void redrawLine(const std::string &prompt, const std::string &input);
}

