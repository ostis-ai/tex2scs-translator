#include "sc_scn_tex_qq_command.h"

ScScnTexCommandResult ScSCnTexQQCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScStringStream stream;
  stream << "\"" << params.at(1) << "\"";

  return stream;
}
