#pragma once

#include "sc_scn_tex_list_command.h"

class ScSCnTexListItemCommand : public ScSCnTexListCommand
{
public:
  ScSCnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScSCnTexCommandParams const & params) override;
};
