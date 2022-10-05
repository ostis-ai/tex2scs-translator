#include "sc_scn_tex_list_item_command.h"

ScScnTexCommandResult ScSCnTexListItemCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  return "";

  std::string const & string = params.at(1);

  return SCsStream().Formatted([&string]() -> SCsStream {
    return { "<li>", string, "</li>" };
  });
}
