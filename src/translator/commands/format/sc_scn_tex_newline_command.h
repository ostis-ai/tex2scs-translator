#pragma once

#include "translator/commands/sc_scn_tex_command.h"

class ScSCnTexNewLineCommand : public ScSCnTexCommand
{
public:
  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
