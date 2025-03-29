#include "sc_scn_tex_start_substruct_command.h"

ScSCnTexCommandResult ScSCnTexStartSubstructCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  return SCsStream()
  .Formatted([](SCsStream & stream) -> SCsStream {
    return { "= [*" };
  });
}
