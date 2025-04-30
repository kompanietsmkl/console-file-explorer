#pragma once
#include "Command.hpp"

class TouchCommand: public Command{
public:
  void execute(const std::string &) override;
};