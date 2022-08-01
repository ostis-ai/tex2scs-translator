#include "sc_scn_tex_list_item_command.h"

ScScnTexCommandResult ScSCnTexListItemCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScStringStream stream;
  if (history.at(history.size() - 1) != "begin")
    stream << "</li>\n";

  stream << offset << "\t<li>";

  return stream;
}
