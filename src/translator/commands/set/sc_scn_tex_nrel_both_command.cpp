#include "sc_scn_tex_nrel_both_command.h"

ScScnTexCommandResult ScSCnTexNrelBothCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & relation = tree.Add(params.at(0));
  std::string subject;
  if (params.at(2) == "[")
    subject = params.at(2);
  else
    subject = tree.Add(params.at(2));

  ScStringStream stream;
  stream << StartLine() << offset << "<=> " << relation << ": " << subject << EndLine();

  return stream;
}
