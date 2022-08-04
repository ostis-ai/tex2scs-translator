#pragma once

#include "sc_scn_tex_has_element_list_command.h"

class ScSCnTexSdClassCommand : public ScSCnTexHasElementListCommand
{
public:
  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
