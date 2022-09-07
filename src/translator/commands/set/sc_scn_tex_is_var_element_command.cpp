#include "sc_scn_tex_is_var_element_command.h"

ScScnTexCommandResult ScSCnTexIsVarElementCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & set = tree.Add(params.at(0));

  ScStringStream stream;
  stream << StartLine(history) << "\n" << offset << "_<- " << set;

  return stream;
}
