#pragma once

#include "../sc_scn_tex_command.h"

class ScSCnTexTextRelationCommand : public ScSCnTexCommand
{
public:
  ScScnTexCommandResult Complete(ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
