#include "sc_scn_tex_uline_command.h"

ScScnTexCommandResult ScSCnTexUlineCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & text = params.at(1);

  return SCsStream().Row([&text]() -> SCsStream {
    return { "<u>", text, "</u>" };
  });
}
