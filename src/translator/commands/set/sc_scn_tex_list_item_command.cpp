#include "sc_scn_tex_list_item_command.h"

ScSCnTexCommandResult ScSCnTexListItemCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  if (history.at(history.size() - 2) == "begin")
    return "";

  return SCsStream()
    .Offset([]() -> SCsStream { return { "<li>" };});
}
