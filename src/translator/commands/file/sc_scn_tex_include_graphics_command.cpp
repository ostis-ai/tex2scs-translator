#include "sc_scn_tex_include_graphics_command.h"

ScSCnTexCommandResult ScSCnTexIncludeGraphicsCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  return params.at(1);
}
