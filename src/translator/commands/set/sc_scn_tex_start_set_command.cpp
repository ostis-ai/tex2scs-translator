#include "sc_scn_tex_start_set_command.h"

ScScnTexCommandResult ScSCnTexStartSetCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScStringStream stream;
  stream << StartLine(history) << offset << "{\n";

  return stream;
}
