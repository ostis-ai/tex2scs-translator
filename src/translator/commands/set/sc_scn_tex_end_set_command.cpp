#include "sc_scn_tex_end_set_command.h"

ScSCnTexCommandResult ScSCnTexEndSetCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  return SCsStream()
  .PreFormatted()
  .Formatted([](SCsStream & stream) -> SCsStream {
    return { ")" };
  });
}
