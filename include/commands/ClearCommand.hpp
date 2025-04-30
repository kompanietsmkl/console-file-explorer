#pragma once
#include "Command.hpp"

class ClearCommand: public Command{
public:
  void execute(const std::string &arg) override;
};