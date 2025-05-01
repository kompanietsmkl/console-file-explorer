#pragma once
#include "Command.hpp"

class MakeDirCommand: public Command{
public:
  void execute(const std::string &) override;
};