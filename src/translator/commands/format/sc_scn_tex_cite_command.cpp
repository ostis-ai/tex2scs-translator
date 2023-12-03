#include "sc_scn_tex_cite_command.h"

ScScnTexCommandResult ScSCnTexCiteCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  return params.at(1);
}
