#include "sc_scn_tex_subset_command.h"

ScScnTexCommandResult ScSCnTexSubsetCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScScnTexCommandParams newParams = { "включение", "/", params.at(0) };

  return ScSCnTexNrelFromCommand::Complete(history, tree, newParams);
}
