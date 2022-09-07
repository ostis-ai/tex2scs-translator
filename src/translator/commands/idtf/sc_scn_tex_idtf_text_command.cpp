#include "sc_scn_tex_idtf_text_command.h"

ScScnTexCommandResult ScSCnTexIdtfTextCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScScnTexCommandParams newParams = params;
  newParams.insert(newParams.begin(), "идентификатор");
    
  return ScSCnTexTextRelationCommand::Complete(history, tree, newParams);
}
