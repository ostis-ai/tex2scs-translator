#include "sc_scn_tex_include_graphics_command.h"

ScScnTexCommandResult ScSCnTexIncludeGraphicsCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  return tree.Add(params.at(2));
}
