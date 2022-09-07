#include "sc_scn_tex_idtf_command.h"

ScScnTexCommandResult ScSCnTexIdtfCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScScnTexCommandParams newParams = { "идентификатор", "/" };
  newParams.push_back(params.at(0));
  newParams.push_back("/");

  return ScSCnTexTextRelationCommand::Complete(history, tree, newParams);
}
