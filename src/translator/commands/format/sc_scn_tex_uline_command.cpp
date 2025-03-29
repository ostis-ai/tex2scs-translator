#include "sc_scn_tex_uline_command.h"

ScSCnTexCommandResult ScSCnTexUlineCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  std::string const & text = params.at(1);

  return SCsStream().Row([&text]() -> SCsStream {
    return { "<u>", text, "</u>" };
  });
}
