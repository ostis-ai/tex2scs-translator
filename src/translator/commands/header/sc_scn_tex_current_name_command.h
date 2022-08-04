#pragma once

#include "sc_scn_tex_header_command.h"

class ScSCnTexCurrentNameCommand : public ScSCnTexHeaderCommand
{
public:
  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
