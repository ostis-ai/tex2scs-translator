#include "sc_scn_tex_textit_command.h"

ScScnTexCommandResult ScSCnTexTextitCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & text = params.at(1);

  return SCsStream().Row([&text]() -> SCsStream {
    return { "<i>", text, "</i>" };
  });
}
