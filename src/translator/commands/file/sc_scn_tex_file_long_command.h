#pragma once

#include "translator/commands/sc_scn_tex_command.h"

class ScSCnTexFileLongCommand : public ScSCnTexCommand
{
public:
  ScSCnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScSCnTexCommandParams const & params) override;
};
