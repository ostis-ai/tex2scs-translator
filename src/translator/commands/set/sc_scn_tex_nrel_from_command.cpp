#include "sc_scn_tex_nrel_from_command.h"
#include "../file/sc_scn_tex_file_long_command.h"

ScScnTexCommandResult ScSCnTexNrelFromCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  scs_arrow = "=> ";
  std::string subject;
  if (params[params.size() - 2][0] == '[')
    subject = params.at(params.size() - 2);
  else
    subject = tree.Add(params.at(params.size() - 2));
    
  ScStringStream stream;
  stream << ScSCnTexRelCommand::Complete(history, tree, params);
  stream << "\n" << offset << subject;
  
  return stream;
}
