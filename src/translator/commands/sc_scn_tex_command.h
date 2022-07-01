#pragma once

#include <string>
#include <vector>

using ScScnTexCommandParams = std::vector<std::string>;
using ScScnTexCommandResult = std::string;

class ScSCnTexCommand
{
public:
  virtual ScScnTexCommandResult Complete(ScScnTexCommandParams const & params) = 0;

  virtual ~ScSCnTexCommand() = default;
};
