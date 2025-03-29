#include "sc_scn_tex_textbf_command.h"

ScSCnTexCommandResult ScSCnTexTextbfCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  std::string const & text = params.at(1);

  return SCsStream().Row([&text]() -> SCsStream {
    return { "<b>", text, "</b>" };
  });
}
