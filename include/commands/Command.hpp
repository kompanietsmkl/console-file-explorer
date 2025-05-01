#pragma once
#include "utils/FilePermissions.hpp"
#include "utils/NameValidation.hpp"
#include "utils/FileClock.hpp"
#include "utils/TerminalInput.hpp"
#include "utils/TextFormat.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <filesystem>

class Command{
public:
  virtual ~Command() = default;
  virtual void execute(const std::string&) = 0;
};