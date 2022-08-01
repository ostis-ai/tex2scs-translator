#include "sc_scn_tex_superset_command.h"

ScScnTexCommandResult ScSCnTexSupersetCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScScnTexCommandParams newParams = { "включение", "/", params.at(0) };

  return ScSCnTexNrelToCommand::Complete(history, tree, newParams);
}
