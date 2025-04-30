#pragma once
#include "commands/Command.hpp"
#include "commands/ChangeDirCommand.hpp"
#include "commands/ClearCommand.hpp"
#include "commands/ListCommand.hpp"
#include "commands/MakeDirCommand.hpp"
#include "commands/PrintWorkingDirCommand.hpp"
#include "commands/RemoveDirCommand.hpp"
#include "commands/TouchCommand.hpp"
#include <map>
#include <iostream>

class CommandProcessor{
private:
  std::map<std::string, std::unique_ptr<Command>> commands;
public:
  CommandProcessor(){
    commands["cd"] = std::make_unique<ChangeDirCommand>();
    commands["clear"] = std::make_unique<ClearCommand>();
    commands["dir"] = std::make_unique<ListCommand>();
    commands["ls"] = std::make_unique<ListCommand>();
    commands["mkdir"] = std::make_unique<MakeDirCommand>();
    commands["pwd"] = std::make_unique<PrintWorkingDirCommand>();
    commands["rmdir"] = std::make_unique<RemoveDirCommand>();
    commands["touch"] = std::make_unique<TouchCommand>();
  }

  bool execute_command(const std::string &input_line);
};