#pragma once
#include "utils/FileUtils.hpp"
#include "utils/PathUtils.hpp"
#include "utils/TimeUtils.hpp"
#include "utils/FormatUtils.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <filesystem>

class Command{
public:
  virtual ~Command() = default;
  virtual void execute(const std::string&) = 0;
};