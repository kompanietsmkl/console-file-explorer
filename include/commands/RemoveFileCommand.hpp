#pragma once
#include "Command.hpp"

class RemoveFileCommand: public Command{
public:
  void execute(const std::string &) override;
};