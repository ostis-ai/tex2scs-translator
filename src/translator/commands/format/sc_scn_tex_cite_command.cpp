#include "sc_scn_tex_cite_command.h"

ScSCnTexCommandResult ScSCnTexCiteCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  return params.at(1);
}
