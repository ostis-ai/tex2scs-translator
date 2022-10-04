#include "sc_scn_tex_nrel_both_command.h"

ScScnTexCommandResult ScSCnTexNrelBothCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  scs_arrow = "<=> ";
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
