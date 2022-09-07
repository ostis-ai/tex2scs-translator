#include "sc_scn_tex_has_var_element_role_command.h"

ScScnTexCommandResult ScSCnTexHasVarElementRoleCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & role = tree.Add(params.at(0));
  std::string const & subject = tree.Add(params.at(2));

  ScStringStream stream;
  stream << StartLine(history) << "\n" << offset << "_-> " << role << ":: " << subject;

  return stream;
}
