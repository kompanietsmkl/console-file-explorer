#pragma once
#include "Command.hpp"

class PrintWorkingDirCommand: public Command{
public:
  void execute(const std::string &arg) override;
};