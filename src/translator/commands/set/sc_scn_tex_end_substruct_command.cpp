#include "sc_scn_tex_end_substruct_command.h"

ScScnTexCommandResult ScSCnTexEndSubstructCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  return SCsStream().Formatted([](SCsStream & stream) -> SCsStream {
    return { "*]" };
  });
}
