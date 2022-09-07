#include "sc_scn_tex_scnitem_command.h"

ScScnTexCommandResult ScSCnTexScnitemCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScStringStream stream;
  if (history.at(history.size() - 1) != "begin")
    stream << ";\n" << params.at(0);
  else stream << "\n" << params.at(0);

  return stream;
}
