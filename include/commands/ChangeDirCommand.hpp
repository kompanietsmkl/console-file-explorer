#pragma once
#include "Command.hpp"

class ChangeDirCommand: public Command{
public:
  void execute(const std::string &) override;
};