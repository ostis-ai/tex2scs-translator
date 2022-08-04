#include "sc_scn_tex_start_substruct_command.h"

ScScnTexCommandResult ScSCnTexStartSubstructCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScStringStream stream;
  stream << StartLine() << offset << "= [*\n" << EndLine();

  return stream;
}
