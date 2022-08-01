#include "sc_scn_tex_textit_command.h"

ScScnTexCommandResult ScSCnTexTextitCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & text = params.at(0);
  std::string const & idtf = tree.Add(text);

  ScStringStream stream;
  stream << "<i>" << text << "</i>";

  return stream;
}
