#include "sc_scn_tex_rel_command.h"

ScScnTexCommandResult ScSCnTexRelCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string current_command = history.at(history.size() - 1);
  std::string relation = tree.Add(params.at(0));
    
  ScStringStream stream;
  stream << StartLine(history) << "\n" << offset << scs_arrow << relation << ":";

  for (size_t param = 1; params[param] != "/"; ++param)
  {
    relation = tree.Add(params.at(param));
    stream << "\n" << offset << std::string(scs_arrow.length(), ' ') << relation << ":";
  }
  
  return stream;
}
