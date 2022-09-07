#include "sc_scn_tex_nrel_superset_command.h"

ScScnTexCommandResult ScSCnTexNrelSupersetCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScScnTexCommandParams newParams = params;
  newParams.insert(newParams.begin(), "включение");

  return ScSCnTexNrelToCommand::Complete(history, tree, newParams);
}
