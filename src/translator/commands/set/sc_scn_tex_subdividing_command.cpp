#include "sc_scn_tex_subdividing_command.h"

ScScnTexCommandResult ScSCnTexSubdividingCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScScnTexCommandParams newParams = { "разбиение", "/" };
  newParams.insert(newParams.cend(), params.cbegin(), params.cend());

  return ScSCnTexNrelFromSetCommand::Complete(history, tree, newParams);
}
