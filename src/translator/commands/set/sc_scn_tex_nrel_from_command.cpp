#include "sc_scn_tex_nrel_from_command.h"
#include "../file/sc_scn_tex_file_long_command.h"

ScScnTexCommandResult ScSCnTexNrelFromCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string relation = tree.Add(params.at(0));
  std::string subject;
  if (params[params.size() - 2][0] == '[')
    subject = params.at(params.size() - 2);
  else
    subject = tree.Add(params.at(params.size() - 2));
    
  ScStringStream stream;
  stream << StartLine(history) << "\n" << offset << "=> " << relation << ":";

  for (size_t param = 1; params[param] != "/"; ++param)
  {
    relation = tree.Add(params.at(param));
    stream << "\n" << offset << "   " << relation << ":";
  }
  stream << "\n" << offset << subject;
  
  return stream;
}
