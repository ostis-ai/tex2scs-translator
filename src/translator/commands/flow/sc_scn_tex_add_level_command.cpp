#include "sc_scn_tex_add_level_command.h"

ScScnTexCommandResult ScSCnTexAddLevelCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & number = params.at(0);

  if (number == "1")
  {
    offset += "\t";
    return "\n\t(*\n";
  }
  else
  {
    offset = offset.substr(0, offset.size() - 1);
    return "\t*)" + EndLine();
  }
}
