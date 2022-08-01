#include "sc_scn_tex_newline_command.h"

ScScnTexCommandResult ScSCnTexNewLineCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  return "\n";
}
