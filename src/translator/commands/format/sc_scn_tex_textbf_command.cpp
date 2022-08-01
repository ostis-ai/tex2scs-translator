#include "sc_scn_tex_textbf_command.h"

ScScnTexCommandResult ScSCnTexTextbfCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & text = params.at(0);
  std::string const & idtf = tree.Add(text);

  ScStringStream stream;
  stream << "<b>" << text << "</b>";

  return stream;
}
