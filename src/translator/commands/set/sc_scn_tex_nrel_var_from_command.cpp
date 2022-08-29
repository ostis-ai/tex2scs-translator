#include "sc_scn_tex_nrel_var_from_command.h"

ScScnTexCommandResult ScSCnTexVarNrelFromCommand::Complete(
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
  stream << StartLine() << offset << "_=> " << relation << ":: " << subject << EndLine();

  return stream;
}
