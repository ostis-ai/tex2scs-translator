#include "sc_scn_tex_explanation_command.h"

ScScnTexCommandResult ScSCnTexExplanationCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScScnTexCommandParams newParams = { "пояснение", "/" };
  newParams.push_back(params.at(0));

  return ScSCnTexTextRelationCommand::Complete(history, tree, newParams);
}
