#pragma once

#include "sc_scn_tex_text_relation_command.h"

class ScSCnTexIdtfCommand : public ScSCnTexTextRelationCommand
{
public:
  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
