#include "sc_scn_tex_nrel_to_command.h"

ScScnTexCommandResult ScSCnTexNrelToCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & relation = tree.Add(params.at(0));
  std::string const & subject = tree.Add(params.at(2));

  ScStringStream stream;
  stream << StartLine() << offset << "<= " << relation << ": " << subject << EndLine();

  return stream;
}
