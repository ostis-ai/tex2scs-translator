#include "sc_scn_tex_struct_header_command.h"

ScSCnTexCommandResult ScSCnTexStructHeaderCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  std::string const & identifier = params.at(1);
  std::string const & systemIdentifier = tree.Add(identifier, "sc_node_structure");

  return SCsStream()
    .PreFormatted()
    .SetCurrentCommand(params.at(0))
    .Formatted([&systemIdentifier]() -> SCsStream {
      return { systemIdentifier };
    });
}
