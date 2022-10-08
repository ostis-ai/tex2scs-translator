#include "sc_scn_tex_structidtf_command.h"

ScScnTexCommandResult ScSCnTexStructIdtfCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & idtf = params.at(1);

  return SCsStream().Row([&idtf]() -> SCsStream {
    return { "<b><em>", idtf, "</b></em>]" };
  });
}
