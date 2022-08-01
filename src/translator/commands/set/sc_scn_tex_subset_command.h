#pragma once

#include "sc_scn_tex_nrel_from_command.h"

class ScSCnTexSubsetCommand : public ScSCnTexNrelFromCommand
{
public:
  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
