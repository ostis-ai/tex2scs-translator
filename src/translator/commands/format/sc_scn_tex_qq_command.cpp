#include "sc_scn_tex_qq_command.h"

ScSCnTexCommandResult ScSCnTexQQCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  ScStringStream stream;
  stream << "\"" << params.at(1) << "\"";

  return stream;
}
