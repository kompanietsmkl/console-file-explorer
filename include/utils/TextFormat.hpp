#pragma once
#include <string>

namespace format::color{
  constexpr std::string_view RED = "\033[0;31m";
  constexpr std::string_view GREEN = "\033[0;32m";
  constexpr std::string_view YELLOW = "\033[0;33m";
  constexpr std::string_view RESET = "\033[0m";
  
  namespace rgb{
    constexpr std::string_view YELLOW = "\033[38;2;254;222;93m";
  }
}