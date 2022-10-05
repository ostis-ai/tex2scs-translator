#include "sc_scn_tex_textbf_command.h"

ScScnTexCommandResult ScSCnTexTextbfCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & text = params.at(1);
  std::string const & idtf = tree.Add(text);

  return SCsStream().Row([&text]() -> SCsStream {
    return { "<b>", text, "</b>" };
  });
}
