#pragma once

#include "../sc_scn_tex_command.h"

class ScSCnTexStartSubstructCommand : public ScSCnTexCommand
{
public:
  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
