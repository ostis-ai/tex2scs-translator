#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "tree/sc_scn_prefix_tree.h"

using ScScnTexCommandParams = std::vector<std::string>;
using ScScnTexCommandResult = std::string;

class ScSCnTexCommand
{
public:
  virtual ScScnTexCommandResult Complete(ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) = 0;

  virtual ~ScSCnTexCommand() = default;
};
