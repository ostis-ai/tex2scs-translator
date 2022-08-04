#include "sc_scn_tex_sd_relation_command.h"

ScScnTexCommandResult ScSCnTexSdRelationCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScScnTexCommandParams newParams = { "исследуемое отношение", "/" };
  newParams.insert(newParams.cend(), params.cbegin(), params.cend());

  return ScSCnTexHasElementListCommand::Complete(history, tree, newParams);
}
