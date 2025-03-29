#include "sc_scn_tex_struct_identifier_command.h"

ScSCnTexCommandResult ScSCnTexStructIdentifierCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  std::string const & identifier = params.at(1);

  return SCsStream().Row([&identifier]() -> SCsStream {
    return { "<b><em>", identifier, "</b></em>" };
  });
}
