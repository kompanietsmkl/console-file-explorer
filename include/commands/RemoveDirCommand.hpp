#pragma once
#include "Command.hpp"

class RemoveDirCommand: public Command{
public:
  void execute(const std::string &arg) override;
};