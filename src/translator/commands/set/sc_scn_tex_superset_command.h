#pragma once

#include "sc_scn_tex_nrel_to_command.h"

class ScSCnTexSupersetCommand : public ScSCnTexNrelToCommand
{
public:
  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
