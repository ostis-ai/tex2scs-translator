#pragma once

#include "sc_scn_tex_struct_header_command.h"

class ScSCnTexSectionHeaderCommand : public ScSCnTexStructHeaderCommand
{
public:
  ScSCnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScSCnTexCommandParams const & params) override;
};
