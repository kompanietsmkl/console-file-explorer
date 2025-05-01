#pragma once
#include "Command.hpp"

class TreeCommand: public Command{
public:
  void execute(const std::string &) override;
};