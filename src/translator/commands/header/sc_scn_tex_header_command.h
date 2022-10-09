#pragma once

#include "../sc_scn_tex_command.h"

class ScSCnTexHeaderCommand : public ScSCnTexCommand
{
public:
  static std::string lastHeader;

  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
