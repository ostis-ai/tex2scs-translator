#pragma once

#include "sc_scn_tex_has_element_role_command.h"

class ScSCnTexSdMainClassCommand : public ScSCnTexHasElementRoleCommand
{
public:
  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
