#include "sc_scn_tex_struct_header_command.h"

ScScnTexCommandResult ScSCnTexStructHeaderCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & idtf = params.at(1);
  std::string const & systemIdtf = tree.Add(idtf, "sc_node_struct");

  return SCsStream()
    .SetCurrentCommand(params.at(0))
    .Formatted([&systemIdtf]() -> SCsStream {
      return { systemIdtf };
    });
}
