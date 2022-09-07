#include "sc_scn_tex_is_element_command.h"

ScScnTexCommandResult ScSCnTexIsElementCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & set = tree.Add(params.at(0));

  ScStringStream stream;
  stream << StartLine(history) << "\n" << offset << "<- " << set;

  return stream;
}
