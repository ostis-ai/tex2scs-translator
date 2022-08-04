#include "sc_scn_tex_sd_main_class_command.h"

ScScnTexCommandResult ScSCnTexSdMainClassCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScScnTexCommandParams newParams = { "максимальный класс объектов исследования", "/" };
  newParams.insert(newParams.cend(), params.cbegin(), params.cend());

  return ScSCnTexHasElementRoleCommand::Complete(history, tree, newParams);
}
