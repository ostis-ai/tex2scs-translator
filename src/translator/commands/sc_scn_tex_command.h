#pragma once

#include <string>
#include <vector>

#include "translator/stream/scs_stream.h"
#include "translator/identifiers-tree/sc_scn_prefix_tree.h"

using ScSCnCommandsHistory = std::vector<std::string>;

using ScScnTexCommandParams = std::vector<std::string>;
using ScScnTexCommandResult = std::string;

class ScSCnTexCommand
{
public:
  virtual ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) = 0;

  virtual ~ScSCnTexCommand() = default;

  uint8_t const COMMAND_TYPE = 0;
};
