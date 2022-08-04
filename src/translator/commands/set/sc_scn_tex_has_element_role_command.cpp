#include "sc_scn_tex_has_element_role_command.h"

ScScnTexCommandResult ScSCnTexHasElementRoleCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & role = tree.Add(params.at(0));
  std::string const & subject = tree.Add(params.at(2));

  ScStringStream stream;
  stream << StartLine() << offset << "-> " << role << ": " << subject << EndLine();

  return stream;
}
