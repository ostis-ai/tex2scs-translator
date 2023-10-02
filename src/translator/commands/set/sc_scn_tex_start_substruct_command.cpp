#include "sc_scn_tex_start_substruct_command.h"

ScScnTexCommandResult ScSCnTexStartSubstructCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  return SCsStream()
  .Formatted([](SCsStream & stream) -> SCsStream {
    return { "= [*" };
  });
}
