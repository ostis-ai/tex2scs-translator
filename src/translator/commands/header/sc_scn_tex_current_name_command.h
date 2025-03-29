#pragma once

#include "sc_scn_tex_header_command.h"

class ScSCnTexCurrentNameCommand : public ScSCnTexHeaderCommand
{
public:
  ScSCnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScSCnTexCommandParams const & params) override;
};
