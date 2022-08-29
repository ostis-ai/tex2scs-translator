#pragma once

#include "sc_scn_tex_header_command.h"

class ScSCnTexHeaderLocalCommand : public ScSCnTexHeaderCommand
{
public:
  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
