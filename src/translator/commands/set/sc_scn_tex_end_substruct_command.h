#pragma once

#include "../sc_scn_tex_command.h"

class ScSCnTexEndSubstructCommand : public ScSCnTexCommand
{
public:
  ScSCnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScSCnTexCommandParams const & params) override;
};
