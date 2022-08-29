#include "sc_scn_tex_idtf_text_command.h"

ScScnTexCommandResult ScSCnTexIdtfTextCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScScnTexCommandParams newParams = { "идентификатор", "/" };
  newParams.push_back(params.at(0));

  return ScSCnTexTextRelationCommand::Complete(history, tree, newParams);
}
