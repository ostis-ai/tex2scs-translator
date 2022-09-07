#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "../stream/sc_string_stream.h"

#include "../tree/sc_scn_prefix_tree.h"

using ScScnTexCommandParams = std::vector<std::string>;
using ScScnTexCommandResult = std::string;

using ScSCnCommandsHistory = std::vector<std::string>;

class ScSCnTexCommand
{
public:
  static std::string offset;

  virtual ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) = 0;

  virtual ~ScSCnTexCommand() = default;

protected:
  static std::string default_command_separator;
  
  std::string StartLine(ScSCnCommandsHistory & history);
};
