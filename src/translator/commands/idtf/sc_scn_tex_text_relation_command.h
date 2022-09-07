#pragma once

#include "../set/sc_scn_tex_nrel_from_command.h"

class ScSCnTexTextRelationCommand : public ScSCnTexNrelFromCommand
{
public:
  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
