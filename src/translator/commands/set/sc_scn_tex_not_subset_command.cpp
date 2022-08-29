#include "sc_scn_tex_not_subset_command.h"

ScScnTexCommandResult ScSCnTexNotSubsetCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & inclusion = tree.Add("включение");
  std::string const & set = tree.Add(params.at(0));
  
  ScStringStream stream;

  stream << StartLine() << offset << "=> " << inclusion << "|: " << set;
  
  return stream;
}
