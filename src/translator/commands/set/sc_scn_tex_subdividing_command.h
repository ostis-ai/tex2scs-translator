#pragma once

#include "sc_scn_tex_nrel_from_set_command.h"

class ScSCnTexSubdividingCommand : public ScSCnTexNrelFromSetCommand
{
public:
  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
