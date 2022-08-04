#include "sc_scn_tex_end_struct_command.h"

ScScnTexCommandResult ScSCnTexEndStructCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScStringStream stream;
  stream << StartLine() << offset << "\n}" << EndLine();

  return stream;
}
