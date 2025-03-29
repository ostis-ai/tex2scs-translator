#pragma once

#include "translator/commands/sc_scn_tex_command.h"

class ScSCnTexFileItemCommand : public ScSCnTexCommand
{
public:
  ScSCnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScSCnTexCommandParams const & params) override;
};
