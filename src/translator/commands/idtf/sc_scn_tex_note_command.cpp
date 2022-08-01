#include "sc_scn_tex_note_command.h"

ScScnTexCommandResult ScSCnTexNoteCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScScnTexCommandParams newParams = { "примечание", "/" };
  newParams.push_back(params.at(0));

  return ScSCnTexTextRelationCommand::Complete(history, tree, newParams);
}
