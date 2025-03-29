#pragma once

#include "translator/commands/sc_scn_tex_command.h"

class ScSCnTexHeaderCommand : public ScSCnTexCommand
{
public:
  static std::string lastHeader;

  ScSCnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScSCnTexCommandParams const & params) override;
};
