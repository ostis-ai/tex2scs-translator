#include "sc_scn_tex_list_item_command.h"

ScScnTexCommandResult ScSCnTexListItemCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  if (history.at(history.size() - 2) == "begin")
    return "";

  return SCsStream()
    .Offset([]() -> SCsStream { return { "<li>" };});
}
