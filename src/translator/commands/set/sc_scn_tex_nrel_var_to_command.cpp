#include "sc_scn_tex_nrel_var_to_command.h"

ScScnTexCommandResult ScSCnTexVarNrelToCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  scs_arrow = "_<= ";
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
