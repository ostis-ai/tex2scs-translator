#pragma once

#include "sc_scn_tex_operation_command.h"

class ScSCnTexMathCommand : public ScSCnTexOperationCommand
{
public:
  ScSCnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScSCnTexCommandParams const & params) override;
};
