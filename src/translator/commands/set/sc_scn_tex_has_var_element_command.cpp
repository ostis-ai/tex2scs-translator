#include "sc_scn_tex_has_var_element_command.h"

ScScnTexCommandResult ScSCnTexHasVarElementCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & set = tree.Add(params.at(0));

  ScStringStream stream;
  stream << StartLine() << offset << "_-> " << set << EndLine();

  return stream;
}
