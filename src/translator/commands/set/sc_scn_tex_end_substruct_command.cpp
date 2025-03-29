#include "sc_scn_tex_end_substruct_command.h"

ScSCnTexCommandResult ScSCnTexEndSubstructCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  return SCsStream().PreFormatted([&](SCsStream & stream) {
    stream.Formatted([]() -> SCsStream {
      return { "*]" };
    });
  });
}
