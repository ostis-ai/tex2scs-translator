#pragma once

#include "../relation/sc_scn_tex_rel_command.h"

class ScSCnTexNrelBothCommand : public ScSCnTexRelCommand
{
public:
  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
