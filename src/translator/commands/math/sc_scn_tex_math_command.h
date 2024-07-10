#pragma once

#include "sc_scn_tex_operation_command.h"

class ScSCnTexMathCommand : public ScSCnTexOperationCommand
{
public:
  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
