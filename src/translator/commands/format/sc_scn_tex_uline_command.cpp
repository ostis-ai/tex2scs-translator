#include "sc_scn_tex_uline_command.h"

ScScnTexCommandResult ScSCnTexUlineCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & text = params.at(0);
  std::string const & idtf = tree.Add(text);

  ScStringStream stream;
  stream << "<u>" << text << "</u>";

  return stream;
}
