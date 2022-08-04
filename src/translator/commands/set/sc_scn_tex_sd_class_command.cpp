#include "sc_scn_tex_sd_class_command.h"

ScScnTexCommandResult ScSCnTexSdClassCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScScnTexCommandParams newParams = { "класс объектов исследования", "/" };
  newParams.insert(newParams.cend(), params.cbegin(), params.cend());

  return ScSCnTexHasElementListCommand::Complete(history, tree, newParams);
}
