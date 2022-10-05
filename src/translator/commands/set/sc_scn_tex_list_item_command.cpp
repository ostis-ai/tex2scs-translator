#include "sc_scn_tex_list_item_command.h"

ScScnTexCommandResult ScSCnTexListItemCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & string = params.at(0);

  return SCsStream().Formatted([&string]() -> SCsStream {
    return { "\t<li>", string, "</li>\n" };
  });
}
