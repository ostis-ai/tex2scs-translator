#include "sc_scn_tex_struct_header_command.h"

ScScnTexCommandResult ScSCnTexStructHeaderCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & idtf = params.at(1);
  std::string const & systemIdtf = tree.Add(idtf);

  return SCsStream()
    .Formatted([&systemIdtf]() -> SCsStream {
      return { systemIdtf };
    })
    .SetLastCommandName(params.at(0))
    .Formatted([]() -> SCsStream {
      return { "<- sc_node_struct" };
    })
    .SetLastCommandName()
    .Formatted([&idtf]() -> SCsStream {
      return { "=> nrel_main_idtf: [", idtf, "] (* <- lang_ru;; *)" };
    });
}
