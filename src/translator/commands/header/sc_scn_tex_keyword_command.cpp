#include "sc_scn_tex_keyword_command.h"

ScScnTexCommandResult ScSCnTexKeywordCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & idtf = params.at(0);

  ScStringStream stream;
  stream << "<em>" << idtf << "</em>";
  return stream;
}
