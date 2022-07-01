#pragma once

#include <utility>
#include <unordered_map>

#include "commands/sc_scn_tex_command.h"

using ScSCnTexCommands = std::unordered_map<std::string, ScSCnTexCommand *>;

class ScSCnTex2SCsTranslator
{
public:
  explicit ScSCnTex2SCsTranslator(ScSCnTexCommands commands)
    : m_commands(std::move(commands)) {}

  bool Run(std::string const & workDirectory, std::string const & targetDirectory)
  {
    return true;
  }

  ~ScSCnTex2SCsTranslator()
  {
    for (auto const & item : m_commands)
      delete item.second;
  }

private:
  ScSCnTexCommands m_commands;
};
