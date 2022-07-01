#pragma once

#include "sc_scn_tex_command.h"

class ScSCnTexIdtfCommand : public ScSCnTexCommand
{
public:
  ScScnTexCommandResult Complete(ScScnTexCommandParams const & params) override;
};
