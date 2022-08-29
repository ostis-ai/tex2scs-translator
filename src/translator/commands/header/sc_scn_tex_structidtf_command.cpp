#include "sc_scn_tex_structidtf_command.h"

ScScnTexCommandResult ScSCnTexStructIdtfCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & idtf = params.at(0);

  ScStringStream stream;
  stream << "<b><em>" << idtf << "</em></b>";
  return stream;
}
