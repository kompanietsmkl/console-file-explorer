#pragma once
#include "Command.hpp"
#include <filesystem>

class ListCommand: public Command{
public:
  std::string wo_quotes(const std::filesystem::path &path);

  void execute(const std::string &) override;
};